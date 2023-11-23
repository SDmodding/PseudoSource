// File Line: 197
// RVA: 0x4CB860
void __fastcall UFG::TSCharacter::TSCharacter(UFG::TSCharacter *this, ASymbol *name, SSActorClass *pClass)
{
  void (__fastcall *v4)(fastdelegate::detail::GenericClass *); // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v5; // [rsp+38h] [rbp-30h] BYREF
  void (__fastcall *v6)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v7)(fastdelegate::detail::GenericClass *); // [rsp+50h] [rbp-18h]

  SSActor::SSActor(this, name, pClass, 1);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNodeComponent);
  this->mpComponent = 0i64;
  this->m_audioController.m_pEvent = 0i64;
  this->mpSimObj.mPrev = &this->mpSimObj;
  this->mpSimObj.mNext = &this->mpSimObj;
  this->mpSimObj.m_pPointer = 0i64;
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSCharacter::`vftable;
  this->mModeFlags = 0;
  this->mTargetThreshold = 0.5;
  this->mpNavigationThread.i_obj_p = 0i64;
  this->mpNavigationThread.i_ptr_id = 0;
  this->mpTargetNode.mPrev = &this->mpTargetNode;
  this->mpTargetNode.mNext = &this->mpTargetNode;
  this->mpTargetNode.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&this->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&this->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&this->mAICharacterControllerBaseComponent);
  this->mpHealthComp = 0i64;
  this->mSpeed = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
  if ( !registeredStaticEventHandlers_0 )
  {
    v4 = (void (__fastcall *)(fastdelegate::detail::GenericClass *))fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !UFG::TSCharacter::EntityDeathHandler )
      v4 = 0i64;
    v7 = v4;
    v6 = UFG::TSCharacter::EntityDeathHandler;
    v5.m_Closure.m_pFunction = v4;
    v5.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)UFG::TSCharacter::EntityDeathHandler;
    UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, &v5, 0x514B87Fu, 0i64, 0);
    registeredStaticEventHandlers_0 = 1;
  }
  if ( this->i_class_p != UFG::SkookumMgr::mspPlayerClass )
    UFG::TSCharacter::EnableScriptControlNPC(this, 0);
}

// File Line: 218
// RVA: 0x4CBEE0
void __fastcall UFG::TSCharacter::~TSCharacter(UFG::TSCharacter *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTargetNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSCharacter::`vftable;
  UFG::TSCharacter::ClearTarget(this);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mActiveAIEntityComponent);
  p_mpTargetNode = &this->mpTargetNode;
  if ( this->mpTargetNode.m_pPointer )
  {
    mPrev = p_mpTargetNode->mPrev;
    mNext = this->mpTargetNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTargetNode->mPrev = p_mpTargetNode;
    this->mpTargetNode.mNext = &this->mpTargetNode;
  }
  this->mpTargetNode.m_pPointer = 0i64;
  v5 = p_mpTargetNode->mPrev;
  v6 = this->mpTargetNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpTargetNode->mPrev = p_mpTargetNode;
  this->mpTargetNode.mNext = &this->mpTargetNode;
  UFG::TSActor::~TSActor(this);
}

// File Line: 228
// RVA: 0x5118D0
UFG::TSCharacter *__fastcall UFG::TSCharacter::find_instance(ASymbol *instance_name)
{
  UFG::TSActor *Actor; // rbx
  UFG::SimObject *SimObject; // rax
  __int16 m_Flags; // dx
  UFG::TSActorComponent *ComponentOfType; // rax
  SSActorClass *i_class_p; // rax
  SSClass *i_superclass_p; // rcx

  Actor = (UFG::TSActor *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                            &SSBrain::c_actor_class_p->i_instances,
                            instance_name);
  if ( (Actor
     || (SimObject = (UFG::SimObject *)UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)instance_name)) != 0i64
     && ((m_Flags = SimObject->m_Flags, (m_Flags & 0x4000) == 0)
       ? (m_Flags >= 0
        ? ((m_Flags & 0x2000) == 0
         ? ((m_Flags & 0x1000) == 0
          ? (ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                          SimObject,
                                                          UFG::TSActorComponent::_TypeUID))
          : (ComponentOfType = (UFG::TSActorComponent *)SimObject->m_Components.p[2].m_pComponent))
         : (ComponentOfType = (UFG::TSActorComponent *)SimObject->m_Components.p[3].m_pComponent))
        : (ComponentOfType = (UFG::TSActorComponent *)SimObject->m_Components.p[4].m_pComponent))
       : (ComponentOfType = (UFG::TSActorComponent *)SimObject->m_Components.p[4].m_pComponent),
         ComponentOfType && (Actor = UFG::TSActorComponent::GetActor(ComponentOfType)) != 0i64))
    && ((i_class_p = (SSActorClass *)Actor->i_class_p, UFG::SkookumMgr::mspCharacterClass == i_class_p)
     || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
     && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass)) )
  {
    return (UFG::TSCharacter *)Actor;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 317
// RVA: 0x4E16D0
UFG::SimObjectCharacter *__fastcall UFG::TSCharacter::GetSimObjectCharacter(UFG::TSCharacter *this)
{
  UFG::SimObjectCharacter *result; // rax

  result = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !result || (result->m_Flags & 0x4000) == 0 )
    return 0i64;
  return result;
}

// File Line: 382
// RVA: 0x4D98C0
void __fastcall UFG::TSCharacter::ClearTarget(UFG::TSCharacter *this)
{
  unsigned int mModeFlags; // eax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTargetNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  mModeFlags = this->mModeFlags;
  if ( (mModeFlags & 1) != 0 )
  {
    this->mModeFlags = mModeFlags & 0xFFFFFFFE;
    m_pPointer = this->mpTargetNode.m_pPointer;
    if ( m_pPointer )
      m_pPointer->vfptr->__vecDelDtor(m_pPointer, 1u);
  }
  p_mpTargetNode = &this->mpTargetNode;
  if ( this->mpTargetNode.m_pPointer )
  {
    mPrev = p_mpTargetNode->mPrev;
    mNext = this->mpTargetNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTargetNode->mPrev = p_mpTargetNode;
    this->mpTargetNode.mNext = &this->mpTargetNode;
  }
  this->mpTargetNode.m_pPointer = 0i64;
  this->mTargetThreshold = 0.5;
}

// File Line: 402
// RVA: 0x4E0740
void __fastcall UFG::TSCharacter::EnableScriptControlNPC(UFG::TSCharacter *this, bool enable)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx
  UFG::SimObjectGame *m_pPointer; // rdi
  UFG::PedSpawnManager *Instance; // rax
  UFG::PedSpawningInfo::eSuspendAction v6; // r8d
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v9; // rax

  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( enable )
    {
      UFG::AIScriptInterfaceComponent::ScriptTaskIncrement(m_pSimComponent);
      m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
      if ( m_pPointer && (this->i_actor_flags & 0x10000) == 0 )
      {
        Instance = UFG::PedSpawnManager::GetInstance();
        v6 = Active;
LABEL_16:
        UFG::PedSpawnManager::SetSuspendOption(Instance, m_pPointer, v6);
      }
    }
    else if ( m_pSimComponent->m_ScriptTaskRefCount )
    {
      UFG::AIScriptInterfaceComponent::ScriptTaskDecrement(m_pSimComponent);
      if ( !HIDWORD(this->mAIScriptInterfaceComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext) )
      {
        m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
        if ( !m_pPointer || (this->i_actor_flags & 0x10000) != 0 )
          m_pPointer = 0i64;
        m_pSceneObj = m_pPointer->m_pSceneObj;
        mpWritableProperties = m_pSceneObj->mpWritableProperties;
        if ( !mpWritableProperties )
          mpWritableProperties = m_pSceneObj->mpConstProperties;
        v9 = PropertyUtils::Get<bool>(
               mpWritableProperties,
               (UFG::qArray<unsigned long,0> *)&qSymbol_CanSuspend,
               DEPTH_RECURSE);
        if ( v9 )
        {
          if ( *v9 )
          {
            Instance = UFG::PedSpawnManager::GetInstance();
            v6 = SuspendAllowed;
            goto LABEL_16;
          }
        }
      }
    }
  }
}

// File Line: 470
// RVA: 0x4E0820
void __fastcall UFG::TSCharacter::EnableScriptControlOnSimObject(UFG::SimObject *pSimObject, bool enable)
{
  UFG::TSActorComponent *m_pComponent; // rcx
  UFG::TSActor *i_obj_p; // rax
  UFG::TSActor *Actor; // rbx

  if ( (pSimObject->m_Flags & 0x4000) != 0 )
  {
    if ( (m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent,
          (i_obj_p = m_pComponent->mpActor.i_obj_p) != 0i64)
      && m_pComponent->mpActor.i_ptr_id == i_obj_p->i_ptr_id
      || enable )
    {
      Actor = UFG::TSActorComponent::GetActor(m_pComponent);
      if ( Actor->i_class_p == UFG::SkookumMgr::mspPlayerClass )
      {
        UFG::TSCharacter::EnableScriptControlNPC((UFG::TSCharacter *)Actor, enable);
        Actor->i_actor_flags |= 4u;
      }
      else
      {
        UFG::TSCharacter::EnableScriptControlNPC((UFG::TSCharacter *)Actor, enable);
      }
    }
  }
}

// File Line: 506
// RVA: 0x4E21D0
bool __fastcall UFG::TSCharacter::IsAtTarget(UFG::TSCharacter *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::NavComponent *m_pComponent; // rcx
  UFG::SimComponent *v5; // rsi
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float v7; // xmm2_4
  float v8; // xmm1_4

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
      if ( m_pComponent )
        return UFG::NavComponent::IsAtDestination(m_pComponent);
    }
  }
  v5 = this->mpTargetNode.m_pPointer;
  if ( !v5 || !this->mTransformNodeComponent.m_pSimComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mpTargetNode.m_pPointer);
  m_pSimComponent = (UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  v7 = m_pSimComponent->mWorldTransform.v3.y - *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v8 = m_pSimComponent->mWorldTransform.v3.x - *(float *)&v5[2].m_BoundComponentHandles.mNode.mPrev;
  return (float)(this->mTargetThreshold * this->mTargetThreshold) > (float)((float)(v7 * v7) + (float)(v8 * v8));
}

// File Line: 541
// RVA: 0x50FD50
void __fastcall UFG::TSCharacter::SetTarget(
        UFG::TSCharacter *this,
        UFG::TransformNodeComponent *transNode,
        UFG::qVector3 *offset,
        __int64 isOffsetLocalCoords,
        float thresholdRadius)
{
  unsigned int mModeFlags; // eax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v11; // rdi
  unsigned int v12; // eax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTargetNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qMatrix44 m; // [rsp+40h] [rbp-48h] BYREF

  mModeFlags = this->mModeFlags;
  if ( (mModeFlags & 1) != 0 )
  {
    this->mModeFlags = mModeFlags & 0xFFFFFFFE;
    m_pPointer = this->mpTargetNode.m_pPointer;
    if ( m_pPointer )
      ((void (__fastcall *)(UFG::SimComponent *, __int64, UFG::qVector3 *, __int64))m_pPointer->vfptr->__vecDelDtor)(
        m_pPointer,
        1i64,
        offset,
        isOffsetLocalCoords);
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v11 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v11 )
  {
    v12 = UFG::qStringHash32("TargetNode", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v11, v12, transNode, 0);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  p_mpTargetNode = &this->mpTargetNode;
  if ( this->mpTargetNode.m_pPointer )
  {
    mPrev = p_mpTargetNode->mPrev;
    mNext = this->mpTargetNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTargetNode->mPrev = p_mpTargetNode;
    this->mpTargetNode.mNext = &this->mpTargetNode;
  }
  this->mpTargetNode.m_pPointer = v14;
  if ( v14 )
  {
    v18 = v14->m_SafePointerList.mNode.mPrev;
    v18->mNext = p_mpTargetNode;
    p_mpTargetNode->mPrev = v18;
    this->mpTargetNode.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = p_mpTargetNode;
  }
  this->mModeFlags |= 1u;
  m.v0 = UFG::qMatrix44::msIdentity.v0;
  m.v1 = UFG::qMatrix44::msIdentity.v1;
  m.v2 = UFG::qMatrix44::msIdentity.v2;
  m.v3.x = offset->x;
  m.v3.y = offset->y;
  m.v3.z = offset->z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetLocalTransform((UFG::TransformNodeComponent *)this->mpTargetNode.m_pPointer, &m);
  if ( thresholdRadius <= 0.5 )
    this->mTargetThreshold = UFG::gMinArriveThresholdRadius;
  else
    this->mTargetThreshold = thresholdRadius;
}

// File Line: 575
// RVA: 0x50FEF0
void __fastcall UFG::TSCharacter::SetTarget(UFG::TSCharacter *this, UFG::qVector3 *pos, float thresholdRadius)
{
  unsigned int mModeFlags; // eax
  UFG::SimComponent *m_pPointer; // rcx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rbx
  unsigned int v10; // eax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTargetNode; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  UFG::SimComponent *v20; // rbx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  UFG::qMatrix44 m; // [rsp+40h] [rbp-88h] BYREF

  mModeFlags = this->mModeFlags;
  if ( (mModeFlags & 1) != 0 )
  {
    this->mModeFlags = mModeFlags & 0xFFFFFFFE;
    m_pPointer = this->mpTargetNode.m_pPointer;
    if ( m_pPointer )
      m_pPointer->vfptr->__vecDelDtor(m_pPointer, 1u);
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v9 )
  {
    v10 = UFG::qStringHash32("TargetNode", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v9, v10, 0i64, 0);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  p_mpTargetNode = &this->mpTargetNode;
  if ( this->mpTargetNode.m_pPointer )
  {
    mPrev = p_mpTargetNode->mPrev;
    mNext = this->mpTargetNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTargetNode->mPrev = p_mpTargetNode;
    this->mpTargetNode.mNext = &this->mpTargetNode;
  }
  this->mpTargetNode.m_pPointer = v12;
  if ( v12 )
  {
    v16 = v12->m_SafePointerList.mNode.mPrev;
    v16->mNext = p_mpTargetNode;
    p_mpTargetNode->mPrev = v16;
    this->mpTargetNode.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = p_mpTargetNode;
  }
  this->mModeFlags |= 1u;
  x = pos->x;
  y = pos->y;
  z = pos->z;
  v20 = this->mpTargetNode.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v20);
  v21 = *((float *)&v20[2].vfptr + 1);
  v22 = *(float *)&v20[2].m_SafePointerList.mNode.mPrev;
  v23 = *((float *)&v20[2].m_SafePointerList.mNode.mPrev + 1);
  m.v0.x = *(float *)&v20[2].vfptr;
  m.v0.y = v21;
  m.v0.z = v22;
  m.v0.w = v23;
  v24 = *((float *)&v20[2].m_SafePointerList.mNode.mNext + 1);
  v25 = *(float *)&v20[2].m_TypeUID;
  v26 = *(float *)&v20[2].m_NameUID;
  m.v1.x = *(float *)&v20[2].m_SafePointerList.mNode.mNext;
  m.v1.y = v24;
  m.v1.z = v25;
  m.v1.w = v26;
  v27 = *(float *)(&v20[2].m_SimObjIndex + 1);
  v28 = *(float *)&v20[2].m_pSimObject;
  v29 = *((float *)&v20[2].m_pSimObject + 1);
  m.v2.x = *(float *)&v20[2].m_Flags;
  m.v2.y = v27;
  m.v2.z = v28;
  m.v2.w = v29;
  m.v3.x = x;
  m.v3.y = y;
  m.v3.z = z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)this->mpTargetNode.m_pPointer, &m);
  if ( thresholdRadius <= 0.5 )
    this->mTargetThreshold = UFG::gMinArriveThresholdRadius;
  else
    this->mTargetThreshold = thresholdRadius;
}

// File Line: 700
// RVA: 0x50E7B0
void __fastcall UFG::TSCharacter::NavigationScriptFinish(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *i_obj_p; // r8

  i_obj_p = this->mpNavigationThread.i_obj_p;
  if ( i_obj_p == pScope || !pScope && i_obj_p->i_ptr_id != this->mpNavigationThread.i_ptr_id )
  {
    this->mpNavigationThread.i_obj_p = 0i64;
    this->mpNavigationThread.i_ptr_id = 0;
  }
}

// File Line: 723
// RVA: 0x50EB70
void __fastcall UFG::TSCharacter::OnInit(UFG::TSCharacter *this, UFG::SimObjectCharacter *pSimObj)
{
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_mAICharacterControllerBaseComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  bool v14; // dl
  UFG::SimObject *m_pPointer; // rax

  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( p_mActiveAIEntityComponent->m_pSimComponent )
  {
    mPrev = p_mActiveAIEntityComponent->mPrev;
    mNext = p_mActiveAIEntityComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mActiveAIEntityComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mActiveAIEntityComponent->m_pSimObject = 0i64;
    p_mActiveAIEntityComponent->mNext = p_mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_8;
  }
  if ( p_mActiveAIEntityComponent->m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || p_mActiveAIEntityComponent->mNext != p_mActiveAIEntityComponent) )
  {
    v7 = p_mActiveAIEntityComponent->mPrev;
    v8 = p_mActiveAIEntityComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mActiveAIEntityComponent->m_Changed = 1;
  p_mActiveAIEntityComponent->m_pSimObject = pSimObj;
  p_mActiveAIEntityComponent->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    p_mActiveAIEntityComponent,
    pSimObj);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &this->mAIScriptInterfaceComponent,
    pSimObj);
  p_mAICharacterControllerBaseComponent = &this->mAICharacterControllerBaseComponent;
  if ( this->mAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v10 = p_mAICharacterControllerBaseComponent->mPrev;
    v11 = this->mAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    this->mAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->mAICharacterControllerBaseComponent.mNext = &this->mAICharacterControllerBaseComponent;
    p_mAICharacterControllerBaseComponent->mPrev = p_mAICharacterControllerBaseComponent;
    goto LABEL_15;
  }
  if ( this->mAICharacterControllerBaseComponent.m_pSimObject
    && (p_mAICharacterControllerBaseComponent->mPrev != p_mAICharacterControllerBaseComponent
     || this->mAICharacterControllerBaseComponent.mNext != &this->mAICharacterControllerBaseComponent) )
  {
    v12 = p_mAICharacterControllerBaseComponent->mPrev;
    v13 = this->mAICharacterControllerBaseComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  this->mAICharacterControllerBaseComponent.m_Changed = 1;
  this->mAICharacterControllerBaseComponent.m_pSimObject = pSimObj;
  this->mAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &this->mAICharacterControllerBaseComponent,
    pSimObj);
  this->mpHealthComp = (UFG::HealthComponent *)pSimObj->m_Components.p[6].m_pComponent;
  UFG::TSActor::OnInit(this, pSimObj);
  v14 = *PropertyUtils::Get<bool>(pSimObj->m_pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_SkookumControl);
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( this->i_class_p == UFG::SkookumMgr::mspPlayerClass )
    {
      UFG::TSCharacter::EnableScriptControlNPC(this, v14);
      this->i_actor_flags |= 4u;
    }
    else
    {
      UFG::TSCharacter::EnableScriptControlNPC(this, v14);
    }
  }
}

// File Line: 740
// RVA: 0x50E940
void __fastcall UFG::TSCharacter::OnDeinit(UFG::TSCharacter *this)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rcx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *p_mActiveAIEntityComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *p_mAIScriptInterfaceComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *p_mAICharacterControllerBaseComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        UFG::FaceActionComponent::StopAllConversations(m_pComponent);
    }
  }
  p_mActiveAIEntityComponent = &this->mActiveAIEntityComponent;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    mPrev = p_mActiveAIEntityComponent->mPrev;
    mNext = this->mActiveAIEntityComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_11:
    this->mActiveAIEntityComponent.m_pSimObject = 0i64;
    this->mActiveAIEntityComponent.mNext = &this->mActiveAIEntityComponent;
    p_mActiveAIEntityComponent->mPrev = p_mActiveAIEntityComponent;
    goto LABEL_12;
  }
  if ( this->mActiveAIEntityComponent.m_pSimObject
    && (p_mActiveAIEntityComponent->mPrev != p_mActiveAIEntityComponent
     || this->mActiveAIEntityComponent.mNext != &this->mActiveAIEntityComponent) )
  {
    v7 = p_mActiveAIEntityComponent->mPrev;
    v8 = this->mActiveAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_11;
  }
LABEL_12:
  this->mActiveAIEntityComponent.m_Changed = 1;
  p_mAIScriptInterfaceComponent = &this->mAIScriptInterfaceComponent;
  if ( this->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v10 = p_mAIScriptInterfaceComponent->mPrev;
    v11 = this->mAIScriptInterfaceComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    this->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_18:
    this->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    this->mAIScriptInterfaceComponent.mNext = &this->mAIScriptInterfaceComponent;
    p_mAIScriptInterfaceComponent->mPrev = p_mAIScriptInterfaceComponent;
    goto LABEL_19;
  }
  if ( this->mAIScriptInterfaceComponent.m_pSimObject
    && (p_mAIScriptInterfaceComponent->mPrev != p_mAIScriptInterfaceComponent
     || this->mAIScriptInterfaceComponent.mNext != &this->mAIScriptInterfaceComponent) )
  {
    v12 = p_mAIScriptInterfaceComponent->mPrev;
    v13 = this->mAIScriptInterfaceComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_18;
  }
LABEL_19:
  this->mAIScriptInterfaceComponent.m_Changed = 1;
  p_mAICharacterControllerBaseComponent = &this->mAICharacterControllerBaseComponent;
  if ( this->mAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v15 = p_mAICharacterControllerBaseComponent->mPrev;
    v16 = this->mAICharacterControllerBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    this->mAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_25:
    this->mAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    this->mAICharacterControllerBaseComponent.mNext = &this->mAICharacterControllerBaseComponent;
    p_mAICharacterControllerBaseComponent->mPrev = p_mAICharacterControllerBaseComponent;
    goto LABEL_26;
  }
  if ( this->mAICharacterControllerBaseComponent.m_pSimObject
    && (p_mAICharacterControllerBaseComponent->mPrev != p_mAICharacterControllerBaseComponent
     || this->mAICharacterControllerBaseComponent.mNext != &this->mAICharacterControllerBaseComponent) )
  {
    v17 = p_mAICharacterControllerBaseComponent->mPrev;
    v18 = this->mAICharacterControllerBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_25;
  }
LABEL_26:
  this->mAICharacterControllerBaseComponent.m_Changed = 1;
  UFG::TSActor::OnDeinit(this);
}

// File Line: 767
// RVA: 0x4DF470
void __fastcall UFG::TSCharacter::Despawn(UFG::TSCharacter *this, bool waitUntilSuspended)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::PedSpawningInfo::eSuspendAction v6; // r8d

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && m_pPointer != UFG::GetLocalPlayer() )
  {
    SSActor::enable_behavior(this, 0);
    if ( waitUntilSuspended )
    {
      Instance = UFG::PedSpawnManager::GetInstance();
      v6 = DeleteOnSuspend;
    }
    else
    {
      if ( (this->i_actor_flags & 0x10000) == 0 )
      {
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, m_pPointer);
        return;
      }
      Instance = UFG::PedSpawnManager::GetInstance();
      v6 = DeleteNow;
    }
    UFG::PedSpawnManager::SetSuspendOption(Instance, m_pPointer, v6);
  }
}

// File Line: 812
// RVA: 0x4F7BB0
void __fastcall UFG::TSCharacter::Mthd_despawn(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter::Despawn(this, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 822
// RVA: 0x50A7B0
void __fastcall UFG::TSCharacter::Mthd_set_suspend_option(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rdi
  UFG::PedSpawningInfo::eSuspendAction v4; // ebx
  UFG::PedSpawnManager *Instance; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (this->i_actor_flags & 0x10000) == 0 )
    {
      v4 = (unsigned int)UFG::PedSpawningInfo::ConvertSymbolToSuspendActionEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      Instance = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::SetSuspendOption(Instance, m_pPointer, v4);
    }
  }
}

// File Line: 839
// RVA: 0x4F2040
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_density_adjust(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PedSpawnManager::AdjustPedDensity(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::PedSpawnManager::UpdateDensityOfActiveZones();
}

// File Line: 847
// RVA: 0x4F2240
void __fastcall UFG::TSCharacter::MthdC_spawn_point_density_adjust(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PedSpawnManager::AdjustSpawnPointDensityModifier(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 858
// RVA: 0x4F20A0
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_target_count(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::PedSpawnManager::SetTargetPedCount((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 868
// RVA: 0x4F2070
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_off_range(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  _((AMD_HD3D *)(*pScope->i_data.i_array_p)->i_data_p);
}

// File Line: 876
// RVA: 0x501720
void __fastcall UFG::TSCharacter::Mthd_is_hidden(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = m_pPointer->m_Components.p[14].m_pComponent) != 0i64
      && LOBYTE(m_pComponent[19].m_TypeUID) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 886
// RVA: 0x508A10
void __fastcall UFG::TSCharacter::Mthd_set_is_hidden(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::CompositeDrawableComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CompositeDrawableComponent *)m_pPointer->m_Components.p[14].m_pComponent;
    if ( m_pComponent )
      UFG::CompositeDrawableComponent::SetIsHidden(
        m_pComponent,
        (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 900
// RVA: 0x4F8CB0
void __fastcall UFG::TSCharacter::Mthd_enable_invulnerable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // r9
  UFG::SimObject *m_pPointer; // rax
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *m_pComponent; // rdx

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        mpHealthComp->m_bIsInvulnerable = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
        v6 = this->mpSimObj.m_pPointer;
        if ( v6 )
        {
          if ( (v6->m_Flags & 0x4000) != 0 )
          {
            m_pComponent = v6->m_Components.p[38].m_pComponent;
            if ( m_pComponent )
              LOBYTE(m_pComponent[1].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
          }
        }
      }
    }
  }
}

// File Line: 922
// RVA: 0x4F9240
void __fastcall UFG::TSCharacter::Mthd_enable_take_damage(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // r8
  UFG::SimObject *m_pPointer; // rax

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
        mpHealthComp->m_bIsTakingDamage = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    }
  }
}

// File Line: 936
// RVA: 0x4F9130
void __fastcall UFG::TSCharacter::Mthd_enable_scripts_during_ai_tree(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    this->mModeFlags |= 4u;
  else
    this->mModeFlags &= ~4u;
}

// File Line: 946
// RVA: 0x4F9110
void __fastcall UFG::TSCharacter::Mthd_enable_script_control(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::TSCharacter::EnableScriptControlNPC(this, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 956
// RVA: 0x4F90F0
void __fastcall UFG::TSCharacter::Mthd_enable_player_script_control(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::TSCharacter::EnablePlayerScriptControl(this, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 968
// RVA: 0x4F8A10
void __fastcall UFG::TSCharacter::Mthd_enable_detailed_on_ground(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  UFG::SimObject *m_pPointer; // rdx
  UFG::CharacterPhysicsComponent *m_pComponent; // rcx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
      if ( m_pComponent )
      {
        if ( i_data_p->i_user_data )
          UFG::CharacterPhysicsComponent::EnableDetailedOnGroundCheck(m_pComponent);
        else
          UFG::CharacterPhysicsComponent::DisableDetailedOnGroundCheck(m_pComponent);
      }
    }
  }
}

// File Line: 991
// RVA: 0x504CA0
void __fastcall UFG::TSCharacter::Mthd_lock_player_gameplay_input(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData *v3; // rcx

  v3 = *pScope->i_data.i_array_p;
  if ( v3->i_data_p->i_user_data )
    UFG::UI::LockGameplayInput((UFG::UI *)v3);
  else
    UFG::UI::UnlockGameplayInput((UFG::UI *)v3);
}

// File Line: 1004
// RVA: 0x502A20
void __fastcall UFG::TSCharacter::Mthd_is_player_gameplay_input_locked(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UI::gUIInputLocked != 0);
}

// File Line: 1023
// RVA: 0x4E06D0
void __fastcall UFG::TSCharacter::EnablePlayerScriptControl(UFG::TSCharacter *this, bool enable)
{
  UFG::SimObject *m_pPointer; // rax

  if ( enable )
    UFG::UI::LockGameplayInput((UFG::UI *)this);
  else
    UFG::UI::UnlockGameplayInput((UFG::UI *)this);
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( this->i_class_p == UFG::SkookumMgr::mspPlayerClass )
    {
      UFG::TSCharacter::EnableScriptControlNPC(this, enable);
      this->i_actor_flags |= 4u;
    }
    else
    {
      UFG::TSCharacter::EnableScriptControlNPC(this, enable);
    }
  }
}

// File Line: 1047
// RVA: 0x504D40
void __fastcall UFG::TSCharacter::Mthd_mission_fail_condition_commit_changes(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  UFG::SimObject *m_pPointer; // rdx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
    i_data_p = (SSInstance *)((char *)i_data_p - 24);
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    m_pPointer = 0i64;
  UFG::MissionFailConditionComponent::HandleAttachment(*(UFG::GameSlice **)&i_data_p[3].i_ptr_id, m_pPointer, 0i64);
}

// File Line: 1053
// RVA: 0x4FFDA0
void __fastcall UFG::TSCharacter::Mthd_has_fail_conditions(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[8].m_pComponent;
    else
      m_pComponent = 0i64;
    *ppResult = SSBoolean::pool_new(m_pComponent != 0i64);
  }
}

// File Line: 1067
// RVA: 0x1536470
__int64 UFG::_dynamic_initializer_for__gsymGrapRCV__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("GrapRCV", -1);
  UFG::gsymGrapRCV.mUID = result;
  return result;
}

// File Line: 1068
// RVA: 0x1536450
__int64 UFG::_dynamic_initializer_for__gsymGrapAttacks__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Attacks", -1);
  UFG::gsymGrapAttacks.mUID = result;
  return result;
}

// File Line: 1071
// RVA: 0x500D40
void __fastcall UFG::TSCharacter::Mthd_is_being_grappled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v3; // bp
  SSActor *i_data_p; // rdi
  SSClass *i_class_p; // rbx
  SSActorClass *v8; // rax
  SSClass *i_superclass_p; // rcx
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned __int8 is_grappling_actor; // al
  UFG::SimObject *v13; // rcx

  if ( ppResult )
  {
    v3 = 0;
    i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
    if ( !i_data_p )
      goto LABEL_18;
    i_class_p = i_data_p->i_class_p;
    if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
    {
      if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
        goto LABEL_18;
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
    }
    if ( i_data_p )
    {
      v8 = (SSActorClass *)i_data_p->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == v8
        || (i_superclass_p = v8->i_superclass_p) != 0i64
        && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
      {
        m_pPointer = this->mpSimObj.m_pPointer;
        if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
          m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
        else
          m_pComponent = 0i64;
        if ( ActionController::IsPlaying((ActionController *)&m_pComponent[3], &UFG::gsymGrapAttacks, 0xFFFFFFFF, 1) )
        {
          is_grappling_actor = UFG::TSCharacter::_is_grappling_actor(
                                 this,
                                 *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count,
                                 this->mpSimObj.m_pPointer);
LABEL_24:
          v3 = is_grappling_actor;
$done_3:
          *ppResult = SSBoolean::pool_new(v3);
          return;
        }
        if ( m_pComponent )
        {
LABEL_23:
          is_grappling_actor = ActionController::IsPlaying(
                                 (ActionController *)&m_pComponent[3],
                                 &UFG::gsymGrapRCV,
                                 0xFFFFFFFF,
                                 1);
          goto LABEL_24;
        }
      }
    }
LABEL_18:
    v13 = this->mpSimObj.m_pPointer;
    if ( v13 && (v13->m_Flags & 0x4000) != 0 )
      m_pComponent = v13->m_Components.p[7].m_pComponent;
    else
      m_pComponent = 0i64;
    if ( !m_pComponent )
      goto $done_3;
    goto LABEL_23;
  }
}

// File Line: 1111
// RVA: 0x500950
void __fastcall UFG::TSCharacter::Mthd_is_armed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v5; // r8
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObject *v7; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        if ( m_pComponent )
        {
          v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
          if ( v7 )
            v5 = UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID) != 0i64;
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 1144
// RVA: 0x500CA0
void __fastcall UFG::TSCharacter::Mthd_is_armed_with_non_stowable_weapon(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // bl
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObject *v7; // rcx
  UFG::GunComponent *ComponentOfType; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        if ( m_pComponent )
        {
          v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
          if ( v7 )
          {
            ComponentOfType = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID);
            if ( ComponentOfType )
              v4 = (unsigned __int8)UFG::GunComponent::IsStowable(ComponentOfType) == 0;
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 1180
// RVA: 0x5009E0
void __fastcall UFG::TSCharacter::Mthd_is_armed_with(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // bl
  UFG::SimComponent *m_pComponent; // rcx
  int i_user_data; // eax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *v10; // rdx
  UFG::SimComponent *v11; // rax
  UFG::SimObjectProp *v12; // rcx
  __int16 v13; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( !m_pPointer )
      goto LABEL_59;
    if ( (m_pPointer->m_Flags & 0x4000) == 0 )
      goto LABEL_59;
    m_pComponent = m_pPointer->m_Components.p[39].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_59;
    v4 = (i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data, i_user_data == qSymbol_knife.mUID)
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 9
       || SLODWORD(m_pComponent[2].vfptr) > 0)
      || i_user_data == qSymbol_beer_bottle.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 3
       || SLODWORD(m_pComponent[1].m_pSimObject) > 0)
      || i_user_data == qSymbol_baton.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 4
       || SHIDWORD(m_pComponent[1].m_pSimObject) > 0)
      || i_user_data == qSymbol_cleaver.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 8
       || SHIDWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) > 0)
      || i_user_data == qSymbol_coke_can.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 1
       || *(int *)&m_pComponent[1].m_Flags > 0)
      || i_user_data == qSymbol_briefcase.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 79
       || (int)m_pComponent[6].m_TypeUID > 0)
      || i_user_data == qSymbol_broom_full.mUID
      && (LOBYTE(m_pComponent[14].m_pSimObject) && *(_DWORD *)&m_pComponent[14].m_Flags == 7
       || SLODWORD(m_pComponent[1].m_BoundComponentHandles.mNode.mNext) > 0);
    if ( i_user_data != qSymbol_camera.mUID )
      goto LABEL_59;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( !LocalPlayer )
      goto LABEL_59;
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      v10 = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v11 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID);
      v10 = v11;
    }
    else
    {
      v10 = LocalPlayer->m_Components.p[20].m_pComponent;
    }
    if ( !v10 )
      goto LABEL_59;
    v12 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 25i64)
                                 + *(_QWORD *)&v10[1].m_TypeUID
                                 + 40);
    if ( !v12 )
      goto LABEL_59;
    v13 = v12->m_Flags;
    if ( (v13 & 0x4000) != 0 || v13 < 0 )
      goto LABEL_54;
    if ( (v13 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v12);
      goto LABEL_56;
    }
    if ( (v13 & 0x1000) != 0 )
LABEL_54:
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v12,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_56:
    if ( ComponentOfTypeHK )
    {
      if ( ComponentOfTypeHK->mIsPhoneCamera )
        v4 = 1;
    }
LABEL_59:
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 1246
// RVA: 0x5025A0
void __fastcall UFG::TSCharacter::Mthd_is_knocked_out(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool IsKnockedOut; // al

  if ( ppResult )
  {
    IsKnockedOut = UFG::IsKnockedOut((UFG::SimObjectGame *)this->mpSimObj.m_pPointer);
    *ppResult = SSBoolean::pool_new(IsKnockedOut);
  }
}

// File Line: 1263
// RVA: 0x502570
void __fastcall UFG::TSCharacter::Mthd_is_killed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool IsKilled; // al

  if ( ppResult )
  {
    IsKilled = UFG::IsKilled((UFG::SimObjectGame *)this->mpSimObj.m_pPointer);
    *ppResult = SSBoolean::pool_new(IsKilled);
  }
}

// File Line: 1279
// RVA: 0x5024B0
void __fastcall UFG::TSCharacter::Mthd_is_invulnerable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax

  if ( ppResult )
  {
    if ( this->mpSimObj.m_pPointer && (mpHealthComp = this->mpHealthComp) != 0i64 && mpHealthComp->m_bIsInvulnerable )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 1293
// RVA: 0x502740
void __fastcall UFG::TSCharacter::Mthd_is_moving(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::NavComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    else
      m_pComponent = 0i64;
    if ( !this->mAIScriptInterfaceComponent.m_pSimComponent || UFG::NavComponent::IsAtDestination(m_pComponent) )
      *ppResult = SSBoolean::pool_new(0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 1308
// RVA: 0x503130
void __fastcall UFG::TSCharacter::Mthd_is_script_controlled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( m_pSimComponent && HIDWORD(m_pSimComponent[1].m_SafePointerList.mNode.mNext) )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 1318
// RVA: 0x5026C0
void __fastcall UFG::TSCharacter::Mthd_is_male(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && v5->m_eGender == eGENDER_MALE )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 1338
// RVA: 0x503B80
void __fastcall UFG::TSCharacter::Mthd_is_using_a_vehicle(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::CharacterOccupantComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent) != 0i64
      && !UFG::CharacterOccupantComponent::IsEnteringOrExiting(m_pComponent) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 1360
// RVA: 0x503C00
void __fastcall UFG::TSCharacter::Mthd_is_using_the_vehicle(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v6; // bl
  UFG::TSVehicle *ArgByNameOrInstance; // rax
  UFG::VehicleOccupantComponent *FilePtr; // rbp
  UFG::SimObject *v9; // rdx
  UFG::CharacterOccupantComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ArgByNameOrInstance = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        if ( ArgByNameOrInstance )
        {
          FilePtr = (UFG::VehicleOccupantComponent *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(ArgByNameOrInstance);
          if ( FilePtr )
          {
            v9 = this->mpSimObj.m_pPointer;
            if ( v9 )
            {
              if ( (v9->m_Flags & 0x4000) != 0 )
              {
                m_pComponent = (UFG::CharacterOccupantComponent *)v9->m_Components.p[44].m_pComponent;
                if ( m_pComponent )
                  v6 = FilePtr == UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
              }
            }
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 1399
// RVA: 0x508E80
void __fastcall UFG::TSCharacter::Mthd_set_non_player_damage_multiplier(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // r8

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    mpHealthComp->m_NonPlayerDamageMultiplier = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1410
// RVA: 0x4FD960
void __fastcall UFG::TSCharacter::Mthd_get_non_player_damage_multiplier(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax
  float m_NonPlayerDamageMultiplier; // xmm0_4

  if ( ppResult )
  {
    mpHealthComp = this->mpHealthComp;
    if ( mpHealthComp )
      m_NonPlayerDamageMultiplier = mpHealthComp->m_NonPlayerDamageMultiplier;
    else
      m_NonPlayerDamageMultiplier = *(float *)&FLOAT_1_0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(m_NonPlayerDamageMultiplier));
  }
}

// File Line: 1425
// RVA: 0x4FD190
void __fastcall UFG::TSCharacter::Mthd_get_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax
  float m_fHealth; // xmm0_4

  if ( ppResult )
  {
    mpHealthComp = this->mpHealthComp;
    if ( mpHealthComp )
      m_fHealth = (float)(int)mpHealthComp->m_fHealth;
    else
      m_fHealth = 0.0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(m_fHealth));
  }
}

// File Line: 1440
// RVA: 0x507740
void __fastcall UFG::TSCharacter::Mthd_set_bone_visual_damage_amount(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *v5; // rdi
  SSData **i_array_p; // r8
  SSData *v7; // rcx
  unsigned int i_user_data; // edx
  const float *p_i_user_data; // rbx
  float v10; // xmm3_4

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      if ( v5 )
      {
        i_array_p = pScope->i_data.i_array_p;
        v7 = i_array_p[2];
        i_user_data = (*i_array_p)->i_data_p->i_user_data;
        p_i_user_data = (const float *)&i_array_p[1]->i_data_p->i_user_data;
        if ( i_user_data && i_array_p[1]->i_data_p != (SSInstance *)-32i64 )
        {
          if ( v7->i_data_p == (SSInstance *)-32i64 )
            v10 = 0.0;
          else
            v10 = *(float *)&v7->i_data_p->i_user_data;
          UFG::CharacterAnimationComponent::SetVisualDamage(v5, i_user_data, *p_i_user_data, v10);
        }
        if ( *p_i_user_data < 0.0099999998 )
          UFG::CharacterAnimationComponent::ApplyCharredEffect(v5, 0.0);
      }
    }
  }
}

// File Line: 1474
// RVA: 0x4F67D0
void __fastcall UFG::TSCharacter::Mthd_clone_visual_damage(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *v5; // rbx
  SSInstance *i_data_p; // rcx
  UFG::SimObjectCVBase *v7; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      if ( v5 )
      {
        i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
        if ( i_data_p )
        {
          v7 = *(UFG::SimObjectCVBase **)&i_data_p[4].i_ref_count;
          if ( v7 )
          {
            m_Flags = v7->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
            }
            else if ( (m_Flags & 0x2000) != 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
            }
            else if ( (m_Flags & 0x1000) != 0 )
            {
              ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v7,
                                                                        UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                        v7,
                                                                        UFG::CharacterAnimationComponent::_TypeUID);
            }
            if ( ComponentOfTypeHK )
              UFG::CharacterAnimationComponent::Clone(v5, ComponentOfTypeHK);
          }
        }
      }
    }
  }
}

// File Line: 1501
// RVA: 0x509200
void __fastcall UFG::TSCharacter::Mthd_set_paint_effect(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *v5; // rax
  SSData **i_array_p; // rdx

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    if ( v5 )
    {
      i_array_p = pScope->i_data.i_array_p;
      UFG::CharacterAnimationComponent::ApplyPaintEffect(
        v5,
        (*i_array_p)->i_data_p->i_user_data != 0,
        *(float *)&i_array_p[1]->i_data_p->i_user_data,
        *(float *)&i_array_p[2]->i_data_p->i_user_data,
        *(float *)&i_array_p[3]->i_data_p->i_user_data);
    }
  }
}

// File Line: 1524
// RVA: 0x507990
void __fastcall UFG::TSCharacter::Mthd_set_charred_effect(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    if ( v5 )
      UFG::CharacterAnimationComponent::ApplyCharredEffect(
        v5,
        *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 1543
// RVA: 0x508390
void __fastcall UFG::TSCharacter::Mthd_set_footstep_override_effect(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::CharacterEffectsComponent *m_pComponent; // rbp
  SSData **i_array_p; // rcx
  unsigned __int64 i_user_data; // r9
  SSInstance *i_data_p; // r14
  const char *v8; // rcx
  unsigned __int64 v9; // r8
  char *v10; // rdx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned __int64 v13; // r8
  const char *v14; // rax
  unsigned __int64 v15; // rdx
  char *v16; // rdi

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterEffectsComponent *)m_pPointer->m_Components.p[38].m_pComponent;
      if ( m_pComponent )
      {
        i_array_p = pScope->i_data.i_array_p;
        i_user_data = (*i_array_p)->i_data_p->i_user_data;
        i_data_p = i_array_p[1]->i_data_p;
        v8 = *(const char **)i_user_data;
        v9 = *(unsigned int *)(i_user_data + 8) + *(_QWORD *)i_user_data + 1i64;
        if ( *(_QWORD *)i_user_data >= v9 )
        {
LABEL_8:
          v11 = -1;
          v12 = -1;
        }
        else
        {
          v10 = (char *)("none" - v8);
          while ( *v8 == v8[(_QWORD)v10] )
          {
            if ( (unsigned __int64)++v8 >= v9 )
              goto LABEL_8;
          }
          v11 = -1;
          v12 = UFG::qStringHashUpper32(*(const char **)i_user_data, -1);
        }
        v13 = i_data_p->i_user_data;
        v14 = *(const char **)v13;
        v15 = *(unsigned int *)(v13 + 8) + *(_QWORD *)v13 + 1i64;
        if ( *(_QWORD *)v13 < v15 )
        {
          v16 = (char *)("none" - v14);
          while ( *v14 == v14[(_QWORD)v16] )
          {
            if ( (unsigned __int64)++v14 >= v15 )
              goto LABEL_16;
          }
          v11 = UFG::qStringHashUpper32(*(const char **)v13, -1);
        }
LABEL_16:
        UFG::CharacterEffectsComponent::SetFootstepOverride(m_pComponent, v12, v11);
      }
    }
  }
}

// File Line: 1585
// RVA: 0x5089C0
void __fastcall UFG::TSCharacter::Mthd_set_invulnerable_to_fire(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[38].m_pComponent;
    if ( m_pComponent )
      LOBYTE(m_pComponent[1].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 1602
// RVA: 0x508660
void __fastcall UFG::TSCharacter::Mthd_set_health_ui_state(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[38].m_pComponent;
    if ( m_pComponent )
      BYTE1(m_pComponent[1].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 1642
// RVA: 0x5085E0
void __fastcall UFG::TSCharacter::Mthd_set_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax

  if ( this->mpHealthComp )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
        UFG::HealthComponent::SetHealth(
          this->mpHealthComp,
          (int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
          0i64);
    }
  }
}

// File Line: 1656
// RVA: 0x4FD530
void __fastcall UFG::TSCharacter::Mthd_get_max_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax
  float m_fMaxHealth; // xmm0_4

  if ( ppResult )
  {
    mpHealthComp = this->mpHealthComp;
    if ( mpHealthComp )
      m_fMaxHealth = (float)(int)mpHealthComp->m_fMaxHealth;
    else
      m_fMaxHealth = 0.0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(m_fMaxHealth));
  }
}

// File Line: 1670
// RVA: 0x508C90
void __fastcall UFG::TSCharacter::Mthd_set_max_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rcx

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    UFG::HealthComponent::SetMaxHealth(mpHealthComp, (int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1683
// RVA: 0x4FD640
void __fastcall UFG::TSCharacter::Mthd_get_min_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax
  float m_fMinHealth; // xmm0_4

  if ( ppResult )
  {
    mpHealthComp = this->mpHealthComp;
    if ( mpHealthComp )
      m_fMinHealth = (float)(int)mpHealthComp->m_fMinHealth;
    else
      m_fMinHealth = FLOAT_N1_0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(m_fMinHealth));
  }
}

// File Line: 1697
// RVA: 0x508CC0
void __fastcall UFG::TSCharacter::Mthd_set_min_health(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rcx

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    UFG::HealthComponent::SetMinHealth(mpHealthComp, (int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1709
// RVA: 0x4FD1E0
void __fastcall UFG::TSCharacter::Mthd_get_health_clamped_to_minimum(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rax

  if ( ppResult )
  {
    mpHealthComp = this->mpHealthComp;
    if ( mpHealthComp )
      *ppResult = SSBoolean::pool_new(mpHealthComp->m_bHealthClampedToMinimum);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 1722
// RVA: 0x508630
void __fastcall UFG::TSCharacter::Mthd_set_health_clamped_to_minimum(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // r8

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    mpHealthComp->m_bHealthClampedToMinimum = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1736
// RVA: 0x50A2D0
void __fastcall UFG::TSCharacter::Mthd_set_regenerative_health_rate(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // r8

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    mpHealthComp->m_fRegenerativeHealthRate = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1745
// RVA: 0x50A2F0
void __fastcall UFG::TSCharacter::Mthd_set_regenerative_health_ratio(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::HealthComponent *mpHealthComp; // rcx

  mpHealthComp = this->mpHealthComp;
  if ( mpHealthComp )
    UFG::HealthComponent::SetRegenerativeHealthRatio(
      mpHealthComp,
      *(const float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
      1);
}

// File Line: 1759
// RVA: 0x505EA0
void __fastcall UFG::TSCharacter::Mthd_poi_get_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObject *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *v8; // rbx
  UFG::CollectibleComponent *CollectibleComponent; // rax
  SSClass *v10; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
        if ( v6 )
        {
          m_Flags = v6->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            v8 = v6->m_Components.p[25].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
              v8 = v6->m_Components.p[10].m_pComponent;
            else
              v8 = (m_Flags & 0x1000) != 0
                 ? v6->m_Components.p[3].m_pComponent
                 : UFG::SimObject::GetComponentOfType(v6, UFG::InterestPoint::_TypeUID);
          }
          else
          {
            v8 = v6->m_Components.p[25].m_pComponent;
          }
          if ( v8 )
          {
            CollectibleComponent = UFG::CollectibleComponent::GetCollectibleComponent(v8->m_pSimObject);
            v10 = UFG::TSCollectible::mspCollectibleClass;
            if ( !CollectibleComponent )
              v10 = UFG::TSInterestPoint::mspInterestPointClass;
            *ppResult = SSInstance::pool_new(v10, (unsigned __int64)v8);
          }
        }
      }
    }
  }
}

// File Line: 1792
// RVA: 0x507270
void __fastcall UFG::TSCharacter::Mthd_set_attracted_to_pois(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[43].m_pComponent;
    if ( m_pComponent )
      LOBYTE(m_pComponent[1].m_SafePointerList.mNode.mNext) ^= (LOBYTE(m_pComponent[1].m_SafePointerList.mNode.mNext) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
  }
}

// File Line: 1813
// RVA: 0x505FF0
void __fastcall UFG::TSCharacter::Mthd_poi_use(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  SSClass *i_class_p; // r8
  UFG::InterestPoint *i_user_data; // rbx
  UFG::ePOIUseType EnumFromSymbol; // r10d
  UFG::SimObject *m_pPointer; // rdx
  UFG::InterestPointUserComponent *m_pComponent; // rcx
  UFG::qStaticSymbol *v11; // r9

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( i_class_p != SSBrain::c_symbol_class_p )
  {
    if ( i_class_p == UFG::TSInterestPoint::mspInterestPointClass )
    {
      i_user_data = (UFG::InterestPoint *)i_data_p->i_user_data;
      goto LABEL_7;
    }
LABEL_6:
    i_user_data = 0i64;
    goto LABEL_7;
  }
  i_user_data = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&i_data_p->i_user_data);
LABEL_7:
  EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                   &UFG::gPOIUseTypeEnum,
                                   (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  if ( i_user_data )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InterestPointUserComponent *)m_pPointer->m_Components.p[43].m_pComponent;
        if ( m_pComponent )
        {
          v11 = &qSymbol_ScriptSkip;
          if ( !*(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) )
            v11 = (UFG::qStaticSymbol *)&UFG::gNullQSymbol;
          UFG::InterestPointUserComponent::UsePOI(m_pComponent, i_user_data, EnumFromSymbol, v11);
        }
      }
    }
  }
}

// File Line: 1840
// RVA: 0x505FB0
void __fastcall UFG::TSCharacter::Mthd_poi_stop_using_use(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult,
        __int64 a4)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::InterestPointUserComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::InterestPointUserComponent *)m_pPointer->m_Components.p[43].m_pComponent;
    if ( m_pComponent )
      UFG::InterestPointUserComponent::StopPOI(m_pComponent, (__int64)m_pPointer, (__int64)ppResult, a4);
  }
}

// File Line: 1860
// RVA: 0x4DCB10
bool __fastcall UFG::TSCharacter::Coro_poi_stop_using(
        UFG::TSCharacter *this,
        SSInvokedCoroutine *pScope,
        __int64 a3,
        __int64 a4)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::InterestPointUserComponent *v6; // rsi
  SSInstance *i_data_p; // rax
  SSClass *i_class_p; // rcx
  UFG::InterestPoint *Named; // rax
  UFG::InterestPoint *v10; // rax
  ActionNode *mBehaviour; // rcx
  ActionNodePlayable *mRootPOINode; // rdx
  UFG::SimObject *v13; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( pScope->i_update_count )
    {
LABEL_18:
      mRootPOINode = (ActionNodePlayable *)this->mRootPOINode;
      if ( mRootPOINode )
      {
        v13 = this->mpSimObj.m_pPointer;
        if ( v13 )
        {
          if ( (v13->m_Flags & 0x4000) != 0 )
          {
            m_pComponent = v13->m_Components.p[7].m_pComponent;
            if ( m_pComponent )
              return ActionController::IsPlaying((ActionController *)&m_pComponent[3], mRootPOINode) == 0;
          }
        }
      }
      return 1;
    }
    this->mRootPOINode = 0i64;
    if ( (m_pPointer->m_Flags & 0x4000) == 0 )
      return 1;
    v6 = (UFG::InterestPointUserComponent *)m_pPointer->m_Components.p[43].m_pComponent;
    if ( !v6 )
      return 1;
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    if ( !i_data_p )
      goto LABEL_10;
    i_class_p = i_data_p->i_class_p;
    if ( i_class_p == SSBrain::c_symbol_class_p )
    {
      Named = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&i_data_p->i_user_data);
      if ( !Named )
        goto LABEL_10;
    }
    else
    {
      if ( i_class_p != UFG::TSInterestPoint::mspInterestPointClass )
        goto LABEL_10;
      Named = (UFG::InterestPoint *)i_data_p->i_user_data;
    }
    if ( Named )
    {
      mBehaviour = Named->mInterestPointType->mBehaviour;
LABEL_17:
      this->mRootPOINode = mBehaviour;
      UFG::InterestPointUserComponent::StopPOI(v6, (__int64)pScope, (__int64)m_pPointer, a4);
      goto LABEL_18;
    }
LABEL_10:
    v10 = v6->mActiveInterestPoint.mInterestPoint.m_pPointer;
    if ( v10 )
      mBehaviour = v10->mInterestPointType->mBehaviour;
    else
      mBehaviour = 0i64;
    goto LABEL_17;
  }
  return 1;
}

// File Line: 1923
// RVA: 0x507AA0
void __fastcall UFG::TSCharacter::Mthd_set_collision_avoidance_type(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int64 m_EnumValue; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  if ( this->mActiveAIEntityComponent.m_pSimComponent && (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol = result;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( collisionAvoidanceEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&collisionAvoidanceEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode;
      collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    m_EnumValue = pTrackEnumBinding.m_EnumValue;
    v6 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v6;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    if ( (unsigned int)m_EnumValue < 9 )
    {
      m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
      if ( m_pSimComponent )
        UFG::AIScriptInterfaceComponent::SetCollisionAvoidanceOverride(m_pSimComponent, m_EnumValue);
    }
  }
}

// File Line: 1951
// RVA: 0x506890
void __fastcall UFG::TSCharacter::Mthd_reset_collision_avoidance_type(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx

  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( m_pSimComponent )
      UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride(m_pSimComponent);
  }
}

// File Line: 1967
// RVA: 0x4FD9B0
void __fastcall UFG::TSCharacter::Mthd_get_objective(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  char *v4; // rdi
  __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+50h] [rbp+8h] BYREF

  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    if ( ppResult )
    {
      v4 = (char *)UFG::AIObjectiveNames[SHIDWORD(this->mActiveAIEntityComponent.m_pSimComponent[65].vfptr)];
      v5 = -1i64;
      do
        ++v5;
      while ( v4[v5] );
      v6 = AMemory::c_req_byte_size_func(v5 + 1);
      str.i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
      *ppResult = SSString::as_instance(&str);
      i_str_ref_p = str.i_str_ref_p;
      if ( str.i_str_ref_p->i_ref_count-- == 1 )
      {
        if ( i_str_ref_p->i_deallocate )
          AMemory::c_free_func(i_str_ref_p->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)i_str_ref_p < i_objects_a
          || (v12 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
              p_i_exp_pool = &pool->i_pool,
              !v12) )
        {
          p_i_exp_pool = &pool->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
      }
    }
  }
}

// File Line: 1985
// RVA: 0x508EA0
void __fastcall UFG::TSCharacter::Mthd_set_objective(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  const char ***p_i_user_data; // rsi
  const char **v6; // rdi
  UFG::eAIObjective v7; // ebx

  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( this->mActiveAIEntityComponent.m_pSimComponent && (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = UFG::AIObjectiveNames;
    v7 = eAI_OBJECTIVE_NONE;
    while ( (unsigned int)UFG::qStringCompareInsensitive(**p_i_user_data, *v6, -1) )
    {
      ++v7;
      ++v6;
      if ( (unsigned int)v7 >= NUM_AI_OBJECTIVES )
        return;
    }
    UFG::ActiveAIEntityComponent::SetCurrentObjective(
      (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent,
      v7,
      "TSCharacter::Mthd_set_objective");
  }
}

// File Line: 2007
// RVA: 0x508F30
void __fastcall UFG::TSCharacter::Mthd_set_objective_and_actor(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::eAIObjective v4; // ebx
  SSActor *i_data_p; // rsi
  const char ***p_i_user_data; // r14
  SSClass *i_class_p; // rdi
  UFG::SimObject *m_pPointer; // rcx
  UFG::TargetingSystemBaseComponent *m_pComponent; // r15
  const char **i; // rdi

  i_array_p = pScope->i_data.i_array_p;
  v4 = eAI_OBJECTIVE_NONE;
  i_data_p = (SSActor *)i_array_p[1]->i_data_p;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    if ( p_i_user_data )
    {
      if ( i_data_p )
      {
        m_pPointer = this->mpSimObj.m_pPointer;
        if ( m_pPointer )
        {
          if ( (m_pPointer->m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
            if ( m_pComponent )
            {
              for ( i = UFG::AIObjectiveNames; (unsigned int)UFG::qStringCompareInsensitive(**p_i_user_data, *i, -1); ++i )
              {
                if ( (unsigned int)++v4 >= NUM_AI_OBJECTIVES )
                  return;
              }
              UFG::ActiveAIEntityComponent::SetCurrentObjective(
                (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent,
                v4,
                "TSCharacter::Mthd_set_objective_and_actor");
              UFG::TargetingSystemBaseComponent::SetTarget(
                m_pComponent,
                eTARGET_TYPE_AI_OBJECTIVE,
                *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count);
            }
          }
        }
      }
    }
  }
}

// File Line: 2033
// RVA: 0x4DEFC0
bool __fastcall UFG::TSCharacter::Coro_wait_until_objective_is_not(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  unsigned int m_EnumValue; // r8d
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  if ( !this->mActiveAIEntityComponent.m_pSimComponent || (*pScope->i_data.i_array_p)->i_data_p == (SSInstance *)-32i64 )
    return 1;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( geAIObjectiveEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&geAIObjectiveEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode;
    geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v5 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v5;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  return HIDWORD(this->mActiveAIEntityComponent.m_pSimComponent[65].vfptr) != m_EnumValue;
}

// File Line: 2060
// RVA: 0x4F6560
void __fastcall UFG::TSCharacter::Mthd_clear_objective(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::ActiveAIEntityComponent::SetCurrentObjective(
      m_pSimComponent,
      eAI_OBJECTIVE_NONE,
      "TSCharacter::Mthd_clear_objective()");
}

// File Line: 2073
// RVA: 0x506DD0
void __fastcall UFG::TSCharacter::Mthd_set_AI_behaviour(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::ActiveAIEntityComponent::SetBehaviourTree(
      m_pSimComponent,
      *(char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2089
// RVA: 0x508C50
void __fastcall UFG::TSCharacter::Mthd_set_max_engagement_distance(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::SimComponent *m_pSimComponent; // rdx
  int i_user_data; // eax

  i_array_p = pScope->i_data.i_array_p;
  m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    HIDWORD(m_pSimComponent[64].m_BoundComponentHandles.mNode.mPrev) = i_array_p[1]->i_data_p->i_user_data;
    LODWORD(m_pSimComponent[64].m_BoundComponentHandles.mNode.mPrev) = i_user_data;
  }
}

// File Line: 2105
// RVA: 0x4F9390
void __fastcall UFG::TSCharacter::Mthd_engage_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rax

  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_EngagementOverrideEnabled = 1;
}

// File Line: 2118
// RVA: 0x506A50
void __fastcall UFG::TSCharacter::Mthd_return_to_default_engagement_of_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[64].m_BoundComponentHandles.mNode.mNext) = 0;
}

// File Line: 2131
// RVA: 0x50B380
void __fastcall UFG::TSCharacter::Mthd_set_xform_to_defend(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r11
  UFG::SimObject *mParent; // rdx

  i_array_p = pScope->i_data.i_array_p;
  mParent = *(UFG::SimObject **)((*i_array_p)->i_data_p->i_user_data + 104);
  if ( mParent )
    mParent = (UFG::SimObject *)mParent->mNode.mParent;
  UFG::TSCharacter::SetPositionToDefend(
    this,
    mParent,
    *(float *)&i_array_p[1]->i_data_p->i_user_data,
    (UFG::qSymbol *)&i_array_p[2]->i_data_p->i_user_data,
    (UFG::qSymbol *)&i_array_p[3]->i_data_p->i_user_data,
    (UFG::qSymbol *)&i_array_p[4]->i_data_p->i_user_data);
}

// File Line: 2150
// RVA: 0x50FCA0
void __fastcall UFG::TSCharacter::SetPositionToDefend(
        UFG::TSCharacter *this,
        UFG::SimObject *object_to_defend,
        float radius,
        UFG::qSymbol *crouchedOrStandingSymbol,
        UFG::qSymbol *abandonPositionWhenCompromisedSymbol,
        UFG::qSymbol *abandonPositionWhenNoGunSymbol)
{
  bool v7; // r8
  bool abandon_when_compromised; // cl
  bool abandon_when_no_gun; // al
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // r10

  if ( crouchedOrStandingSymbol->mUID == qSymbol_Crouched.mUID )
  {
    v7 = 1;
  }
  else
  {
    v7 = 0;
    if ( crouchedOrStandingSymbol->mUID == qSymbol_NotCrouched.mUID )
      v7 = 0;
  }
  if ( abandonPositionWhenCompromisedSymbol->mUID == qSymbol_AbandonPositionWhenCompromised.mUID )
  {
    abandon_when_compromised = 1;
  }
  else
  {
    abandon_when_compromised = 0;
    if ( abandonPositionWhenCompromisedSymbol->mUID == qSymbol_HoldPositionWhenCompromised.mUID )
      abandon_when_compromised = 0;
  }
  if ( abandonPositionWhenNoGunSymbol->mUID == qSymbol_AbandonPositionWhenNoGun.mUID )
  {
    abandon_when_no_gun = 1;
  }
  else
  {
    abandon_when_no_gun = 0;
    if ( abandonPositionWhenNoGunSymbol->mUID == qSymbol_HoldPositionWhenNoGun.mUID )
      abandon_when_no_gun = 0;
  }
  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIScriptInterfaceComponent::SetPositionToDefend(
      m_pSimComponent,
      object_to_defend,
      radius,
      v7,
      abandon_when_compromised,
      abandon_when_no_gun);
}

// File Line: 2211
// RVA: 0x4F6610
void __fastcall UFG::TSCharacter::Mthd_clear_pos_to_defend(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIScriptInterfaceComponent::ClearPositionToDefend(m_pSimComponent);
}

// File Line: 2224
// RVA: 0x4F64A0
void __fastcall UFG::TSCharacter::Mthd_clear_current_emotion(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LODWORD(m_pSimComponent[10].m_BoundComponentHandles.mNode.mNext) = 0;
}

// File Line: 2237
// RVA: 0x507C50
void __fastcall UFG::TSCharacter::Mthd_set_current_emotion(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  const char ***p_i_user_data; // rsi
  int v6; // edi
  const char **v7; // rbx
  UFG::SimComponent *m_pSimComponent; // rax

  i_array_p = pScope->i_data.i_array_p;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = 0;
    v7 = UFG::AIEmotionNames;
    while ( (unsigned int)UFG::qStringCompareInsensitive(*v7, **p_i_user_data, -1) )
    {
      ++v7;
      ++v6;
      if ( (__int64)v7 >= (__int64)&UFG::InterestPointUserComponent::_TypeName )
        return;
    }
    m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( m_pSimComponent )
      LODWORD(m_pSimComponent[10].m_BoundComponentHandles.mNode.mNext) = v6;
  }
}

// File Line: 2278
// RVA: 0x4F5FC0
void __fastcall UFG::TSCharacter::Mthd_begin_fleeing(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) |= 0x10u;
}

// File Line: 2291
// RVA: 0x50C310
void __fastcall UFG::TSCharacter::Mthd_stop_fleeing(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) &= ~0x10u;
}

// File Line: 2304
// RVA: 0x4F43D0
void __fastcall UFG::TSCharacter::Mthd_add_supplementary_attack_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
         i_class_p,
         *i_array_p,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( i_data_p )
      UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(
        m_pSimComponent,
        *(UFG::SimObjectGame **)&i_data_p[1].i_icoroutines_to_update.i_count);
  }
}

// File Line: 2319
// RVA: 0x506740
void __fastcall UFG::TSCharacter::Mthd_remove_supplementary_attack_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
         i_class_p,
         *i_array_p,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( i_data_p )
      UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(
        m_pSimComponent,
        *(UFG::SimObjectGame **)&i_data_p[1].i_icoroutines_to_update.i_count);
  }
}

// File Line: 2334
// RVA: 0x4F4340
void __fastcall UFG::TSCharacter::Mthd_add_scary_actor(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::AIEntityComponent *m_pSimComponent; // rcx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
         i_class_p,
         *i_array_p,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  else
LABEL_6:
    i_data_p = 0i64;
LABEL_7:
  m_pSimComponent = (UFG::AIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( i_data_p )
      UFG::AIEntityComponent::AddThreatTarget(
        m_pSimComponent,
        *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count,
        100.0);
  }
}

// File Line: 2349
// RVA: 0x4F6630
void __fastcall UFG::TSCharacter::Mthd_clear_scary_actors(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIEntityComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIEntityComponent::ClearThreatTargets(m_pSimComponent);
}

// File Line: 2362
// RVA: 0x50C040
void __fastcall UFG::TSCharacter::Mthd_start_holding_action_request(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(
      m_pSimComponent,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2377
// RVA: 0x50C330
void __fastcall UFG::TSCharacter::Mthd_stop_holding_action_request(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIScriptInterfaceComponent::StopHoldingActionRequest(
      m_pSimComponent,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2392
// RVA: 0x50C360
void __fastcall UFG::TSCharacter::Mthd_stop_holding_all_action_requests(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::AIScriptInterfaceComponent::StopHoldingAllActionRequests(m_pSimComponent);
}

// File Line: 2400
// RVA: 0x50A1E0
void __fastcall UFG::TSCharacter::Mthd_set_race(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::RaceTrail *RaceTrail; // rax
  UFG::SimObject *m_pPointer; // r8
  UFG::RaceTrail *v6; // rdi
  __int16 m_Flags; // dx
  UFG::RoadSpaceComponent *m_pComponent; // rax
  UFG::SimObjectGame *v9; // rcx

  RaceTrail = UFG::RaceManager::GetRaceTrail((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  m_pPointer = this->mpSimObj.m_pPointer;
  v6 = RaceTrail;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v9,
                                                    UFG::RoadSpaceComponent::_TypeUID);
      else
        m_pComponent = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                    v9,
                                                    UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
      UFG::RoadSpaceComponent::SetRaceTrail(m_pComponent, v6);
  }
}

// File Line: 2413
// RVA: 0x4FE830
void __fastcall UFG::TSCharacter::Mthd_get_race_index(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // r9
  unsigned int RaceIndex; // ebx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::RacePosition *mPrev; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  RaceIndex = -1;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      mPrev = (UFG::RacePosition *)m_pComponent[26].m_SafePointerList.mNode.mPrev;
      if ( mPrev )
        RaceIndex = UFG::RacePosition::GetRaceIndex(mPrev);
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, RaceIndex);
}

// File Line: 2430
// RVA: 0x4F9DB0
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rdi
  int v5; // ebp
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rsi
  UFG::SimObjectVehicle *SafeSimObjectVehicle; // rbx
  SSData **i_array_p; // rdx
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    return;
  v5 = 0;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_10;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          pScope,
          ppResult) )
  {
    if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
      goto LABEL_10;
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  }
  if ( !i_data_p )
  {
LABEL_10:
    SafeSimObjectVehicle = 0i64;
    goto LABEL_11;
  }
  SafeSimObjectVehicle = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)i_data_p);
LABEL_11:
  UFG::VehicleUtility::ExitVehicleNoAnim(m_pPointer);
  i_array_p = pScope->i_data.i_array_p;
  LOBYTE(v5) = i_array_p[1]->i_data_p->i_user_data == 0;
  UFG::VehicleUtility::PlaceCharacterInVehicle(
    m_pPointer,
    SafeSimObjectVehicle,
    (UFG::eTargetTypeEnum)(v5 + 4),
    i_array_p[2]->i_data_p->i_user_data != 0,
    0,
    1);
  if ( SafeSimObjectVehicle )
    UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(SafeSimObjectVehicle);
  if ( UFG::GetLocalPlayer() == m_pPointer && SafeSimObjectVehicle )
  {
    CurrentBaseCamera = UFG::GetCurrentBaseCamera();
    if ( CurrentBaseCamera )
      ((void (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[14].__vecDelDtor)(CurrentBaseCamera);
    if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(SafeSimObjectVehicle) )
    {
      if ( UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle(SafeSimObjectVehicle) )
        UFG::UI::PauseGame("WorldMap");
    }
  }
}

// File Line: 2499
// RVA: 0x4F9F00
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle_seat(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rdi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rsi
  UFG::SimObjectVehicle *SafeSimObjectVehicle; // rbx
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+80h] [rbp+20h] BYREF

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    return;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_10;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          pScope,
          ppResult) )
  {
    if ( i_class_p != SSBrain::c_symbol_class_p || LODWORD(i_data_p->i_user_data) == -1 )
      goto LABEL_10;
    i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
  }
  if ( !i_data_p )
  {
LABEL_10:
    SafeSimObjectVehicle = 0i64;
    goto LABEL_11;
  }
  SafeSimObjectVehicle = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)i_data_p);
LABEL_11:
  UFG::VehicleUtility::ExitVehicleNoAnim(m_pPointer);
  v8 = UFG::qSymbol::create_from_string(
         &result,
         **(const char ***)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v8->mUID;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gTargetTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  if ( (int)pTrackEnumBinding.m_EnumValue < 91 )
  {
    UFG::VehicleUtility::PlaceCharacterInVehicle(
      m_pPointer,
      SafeSimObjectVehicle,
      (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64,
      0,
      0);
    if ( UFG::GetLocalPlayer() == m_pPointer )
    {
      if ( SafeSimObjectVehicle )
      {
        CurrentBaseCamera = UFG::GetCurrentBaseCamera();
        if ( CurrentBaseCamera )
          ((void (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[14].__vecDelDtor)(CurrentBaseCamera);
      }
    }
  }
  v11 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v11;
}

// File Line: 2551
// RVA: 0x4FA0F0
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle_trunk(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rdi
  UFG::SimObjectVehicle *SafeSimObjectVehicle; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // r14
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    return;
  SafeSimObjectVehicle = 0i64;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p )
  {
    i_class_p = i_data_p->i_class_p;
    if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))i_class_p->vfptr->is_actor_class)(
           i_class_p,
           pScope,
           ppResult) )
    {
      goto LABEL_8;
    }
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
LABEL_8:
      if ( i_data_p )
        SafeSimObjectVehicle = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)i_data_p);
      goto LABEL_11;
    }
  }
  i_data_p = 0i64;
LABEL_11:
  UFG::VehicleUtility::PlaceCharacterInTrunk(m_pPointer, SafeSimObjectVehicle);
  if ( UFG::GetLocalPlayer() == m_pPointer && i_data_p )
  {
    CurrentBaseCamera = UFG::GetCurrentBaseCamera();
    if ( CurrentBaseCamera )
      ((void (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[14].__vecDelDtor)(CurrentBaseCamera);
  }
}

// File Line: 2575
// RVA: 0x4F8B80
void __fastcall UFG::TSCharacter::Mthd_enable_in_car_reactions(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // bl
  UFG::SimComponent *ComponentOfType; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActorAudioComponent::_TypeUID);
    if ( ComponentOfType )
    {
      LOBYTE(ComponentOfType[8].m_pSimObject) &= ~0x10u;
      LOBYTE(ComponentOfType[8].m_pSimObject) |= 16 * v4;
    }
  }
}

// File Line: 2588
// RVA: 0x508BB0
void __fastcall UFG::TSCharacter::Mthd_set_is_tired(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  bool v4; // bl
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                          m_pPointer,
                                                                          UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->mIsTired = v4;
  }
}

// File Line: 2603
// RVA: 0x504E80
void __fastcall UFG::TSCharacter::Mthd_move_stop(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInvokedCoroutine *i_obj_p; // rcx

  UFG::TSCharacter::ClearTarget(this);
  i_obj_p = this->mpNavigationThread.i_obj_p;
  if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id )
    ++i_obj_p->i_pending_count;
  this->mpNavigationThread.i_obj_p = 0i64;
  this->mpNavigationThread.i_ptr_id = 0;
}

// File Line: 2614
// RVA: 0x4FA1D0
void __fastcall UFG::TSCharacter::Mthd_force_update_targeting(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::TargetingSystemPedBaseComponent *v4; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
    if ( v4 )
      v4->m_bForceUpdate = 1;
  }
}

// File Line: 2650
// RVA: 0x4FD580
void __fastcall UFG::TSCharacter::Mthd_get_melee_weapon(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  unsigned __int64 *p_i_user_data; // rdx
  unsigned int EnumFromSymbol; // eax
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimObject *v8; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    p_i_user_data = &(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    EnumFromSymbol = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, (UFG::qSymbol *)p_i_user_data);
    if ( m_pPointer
      && (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent) != 0i64
      && (v8 = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + EnumFromSymbol + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40)) != 0i64 )
    {
      if ( UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID) )
      {
        *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
        return;
      }
    }
    else
    {
      v8 = 0i64;
    }
    *ppResult = UFG::TSActor::SkookumObjFromSimObj(v8);
  }
}

// File Line: 2670
// RVA: 0x4FCE10
void __fastcall UFG::TSCharacter::Mthd_get_firearm(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  unsigned __int64 *p_i_user_data; // rdx
  unsigned int EnumFromSymbol; // eax
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimObject *v8; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    p_i_user_data = &(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    EnumFromSymbol = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, (UFG::qSymbol *)p_i_user_data);
    if ( m_pPointer
      && (m_pComponent = m_pPointer->m_Components.p[20].m_pComponent) != 0i64
      && (v8 = *(UFG::SimObject **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + EnumFromSymbol + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40)) != 0i64
      && UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID) )
    {
      *ppResult = UFG::TSActor::SkookumObjFromSimObj(v8);
    }
    else
    {
      *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    }
  }
}

// File Line: 2692
// RVA: 0x4FCED0
void __fastcall UFG::TSCharacter::Mthd_get_firearm_type(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimObjectProp *v6; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::FireModeInfo *v9; // rcx
  EnumList<unsigned long> *v10; // rax
  ASymbol *null; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer )
      goto LABEL_19;
    if ( (m_pPointer->m_Flags & 0x4000) == 0 )
      goto LABEL_19;
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_19;
    v6 = *(UFG::SimObjectProp **)(56i64
                                * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                     + (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                                       &UFG::gTargetTypeEnum,
                                                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)
                                                     + 8i64)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
    if ( !v6 )
      goto LABEL_19;
    m_Flags = v6->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      goto LABEL_12;
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v6);
      goto LABEL_14;
    }
    if ( (m_Flags & 0x1000) != 0 )
LABEL_12:
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v6,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v6,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_14:
    if ( ComponentOfTypeHK )
    {
      v9 = ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode];
      if ( (int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
        v10 = 0i64;
      else
        v10 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
      null = (ASymbol *)UFG::qSymbol::create_from_string(&result, v10->m_enumName.p[v9->mSimObjectWeaponType]);
      goto LABEL_20;
    }
LABEL_19:
    null = ASymbol::get_null();
LABEL_20:
    *ppResult = SSSymbol::as_instance(null);
  }
}

// File Line: 2726
// RVA: 0x4F8450
void __fastcall UFG::TSCharacter::Mthd_disable_hostile(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rax

  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent->m_HostilityEnabled = 0;
}

// File Line: 2736
// RVA: 0x4F8B60
void __fastcall UFG::TSCharacter::Mthd_enable_hostile(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    HIBYTE(m_pSimComponent[14].m_Flags) = 1;
}

// File Line: 2750
// RVA: 0x5063A0
void __fastcall UFG::TSCharacter::Mthd_reinitialize(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      UFG::SimObjectUtility::ReinitializeSimObject(m_pPointer, 1, 0);
  }
}

// File Line: 2766
// RVA: 0x506910
void __fastcall UFG::TSCharacter::Mthd_reset_state(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      UFG::SimObjectUtility::ResetState(m_pPointer, 0, 0);
  }
}

// File Line: 2782
// RVA: 0x506940
void __fastcall UFG::TSCharacter::Mthd_reset_state_keep_items(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      UFG::SimObjectUtility::ResetState(m_pPointer, 1, 0);
  }
}

// File Line: 2793
// RVA: 0x5117B0
bool __fastcall UFG::TSCharacter::_is_grappling_actor(
        UFG::TSCharacter *this,
        UFG::SimObject *pGrappler,
        UFG::SimObject *pTarget)
{
  UFG::SimComponent *ComponentOfType; // rax
  bool result; // al

  result = 0;
  if ( pGrappler )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(pGrappler, UFG::TargetingSystemPedBaseComponent::_TypeUID);
    if ( ComponentOfType )
    {
      if ( pTarget == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&ComponentOfType[1].m_Flags + 31i64)
                                         + *(_QWORD *)&ComponentOfType[1].m_TypeUID
                                         + 40) )
        return 1;
    }
  }
  return result;
}

// File Line: 2817
// RVA: 0x501690
void __fastcall UFG::TSCharacter::Mthd_is_grappling_actor(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  bool v5; // cl
  UFG::SimObject *v6; // rsi
  UFG::SimComponent *ComponentOfType; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v6 = UFG::TSActor::GetArgByNameOrInstance(pScope, 0)->mpSimObj.m_pPointer;
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemPedBaseComponent::_TypeUID);
      v5 = ComponentOfType
        && v6 == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&ComponentOfType[1].m_Flags + 31i64)
                                    + *(_QWORD *)&ComponentOfType[1].m_TypeUID
                                    + 40);
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 2843
// RVA: 0x500710
void __fastcall UFG::TSCharacter::Mthd_is_a_driver(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rdx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (p = m_pPointer->m_Components.p, (m_pComponent = p[44].m_pComponent) != 0i64)
      && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 4
      && !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)p[44].m_pComponent) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 2869
// RVA: 0x503850
void __fastcall UFG::TSCharacter::Mthd_is_the_driver(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  bool v5; // di
  UFG::TSVehicle *ArgByNameOrInstance; // rax
  UFG::VehicleOccupantComponent *FilePtr; // rax
  UFG::SimComponentHolder *p; // rcx
  UFG::SimComponent *m_pComponent; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ArgByNameOrInstance = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        if ( ArgByNameOrInstance )
        {
          FilePtr = (UFG::VehicleOccupantComponent *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(ArgByNameOrInstance);
          p = m_pPointer->m_Components.p;
          m_pComponent = p[44].m_pComponent;
          if ( m_pComponent )
          {
            if ( FilePtr == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)p[44].m_pComponent)
              && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) == 4 )
            {
              v5 = UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)m_pComponent) == 0;
            }
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 2911
// RVA: 0x501BE0
void __fastcall UFG::TSCharacter::Mthd_is_in_trunk(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  bool v5; // bl
  UFG::TargetingSystemPedBaseComponent *v7; // rax
  UFG::SimObject *v8; // r8
  UFG::SimObject *v9; // rcx

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(m_pPointer);
        if ( v7 )
        {
          v8 = v7->m_pTargets[(unsigned __int8)v7->m_pTargetingMap->m_Map.p[13]].m_pTarget.m_pPointer;
          if ( v8 )
          {
            v9 = this->mpSimObj.m_pPointer;
            if ( !v9 || (v9->m_Flags & 0x4000) == 0 )
              v9 = 0i64;
            v5 = v9 == v8;
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 2943
// RVA: 0x501B20
void __fastcall UFG::TSCharacter::Mthd_is_in_the_trunk(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v6; // bl
  UFG::TSVehicle *ArgByNameOrInstance; // rax
  UFG::SimObjectVehicle *FilePtr; // rax
  UFG::TargetingSystemVehicleComponent *v9; // rax
  UFG::SimObject *v10; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ArgByNameOrInstance = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        FilePtr = Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(ArgByNameOrInstance);
        if ( FilePtr )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>(FilePtr);
          if ( v9 )
          {
            v10 = this->mpSimObj.m_pPointer;
            if ( !v10 || (v10->m_Flags & 0x4000) == 0 )
              v10 = 0i64;
            v6 = v10 == v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[13]].m_pTarget.m_pPointer;
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 2979
// RVA: 0x500780
void __fastcall UFG::TSCharacter::Mthd_is_a_passenger(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::CharacterOccupantComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = (UFG::CharacterOccupantComponent *)m_pPointer->m_Components.p[44].m_pComponent) != 0i64
      && m_pComponent->mTargetType != eTARGET_TYPE_VEHICLE_DRIVER
      && !UFG::CharacterOccupantComponent::IsEnteringOrExiting(m_pComponent) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3003
// RVA: 0x503910
void __fastcall UFG::TSCharacter::Mthd_is_the_passenger(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v6; // di
  UFG::TSVehicle *ArgByNameOrInstance; // rax
  UFG::SimObjectVehicle *FilePtr; // rax
  UFG::SimObject *v9; // rdx
  UFG::VehicleOccupantComponent *v10; // rbp
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rbx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ArgByNameOrInstance = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        FilePtr = Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(ArgByNameOrInstance);
        v9 = this->mpSimObj.m_pPointer;
        v10 = (UFG::VehicleOccupantComponent *)FilePtr;
        if ( v9 )
        {
          if ( (v9->m_Flags & 0x4000) != 0 )
          {
            p = v9->m_Components.p;
            m_pComponent = p[44].m_pComponent;
            if ( m_pComponent )
            {
              if ( v10 == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)p[44].m_pComponent)
                && LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) != 4 )
              {
                v6 = UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)m_pComponent) == 0;
              }
            }
          }
        }
      }
    }
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 3038
// RVA: 0x5025D0
void __fastcall UFG::TSCharacter::Mthd_is_local_player(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    LocalPlayer = UFG::GetLocalPlayer();
    *ppResult = SSBoolean::pool_new(m_pPointer == LocalPlayer);
  }
}

// File Line: 3051
// RVA: 0x4FF230
void __fastcall UFG::TSCharacter::Mthd_get_trunk_vehicle(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::TargetingSystemVehicleComponent *m_pComponent; // rcx
  UFG::TargetingMap *m_pTargetingMap; // rdx
  UFG::TargetingSimObject *m_pTargets; // r8
  UFG::SimObject *v8; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemVehicleComponent *)m_pPointer->m_Components.p[20].m_pComponent;
        if ( m_pComponent )
        {
          m_pTargetingMap = m_pComponent->m_pTargetingMap;
          m_pTargets = m_pComponent->m_pTargets;
          if ( m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK]].m_pTarget.m_pPointer )
          {
            v8 = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[eTARGET_TYPE_VEHICLE]].m_pTarget.m_pPointer;
            if ( v8 )
              *ppResult = UFG::TSActor::SkookumObjFromSimObj(v8);
          }
        }
      }
    }
  }
}

// File Line: 3083
// RVA: 0x4FC2E0
void __fastcall UFG::TSCharacter::Mthd_get_current_vehicle(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponentHolder *p; // rax
  UFG::CharacterOccupantComponent *m_pComponent; // rbx
  UFG::SimObject *CurrentVehicle; // rax

  if ( ppResult )
  {
    *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        p = m_pPointer->m_Components.p;
        m_pComponent = (UFG::CharacterOccupantComponent *)p[44].m_pComponent;
        if ( m_pComponent )
        {
          if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)p[44].m_pComponent) )
          {
            CurrentVehicle = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
            *ppResult = UFG::TSActor::SkookumObjFromSimObj(CurrentVehicle);
          }
        }
      }
    }
  }
}

// File Line: 3108
// RVA: 0x4DF0F0
bool __fastcall UFG::TSCharacter::Coro_wait_until_outside_vehicle(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  return !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 || !m_pPointer->m_Components.p[44].m_pComponent;
}

// File Line: 3125
// RVA: 0x500250
void __fastcall UFG::TSCharacter::Mthd_has_taken_damage(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // bl
  UFG::SimComponent *ComponentOfType; // rax

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer )
    {
      ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::HitReactionComponent::_TypeUID);
      if ( ComponentOfType )
        v4 = *(_DWORD *)(&ComponentOfType[3].m_SimObjIndex + 1) == 1
          && BYTE2(ComponentOfType[2].m_BoundComponentHandles.mNode.mNext);
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 3147
// RVA: 0x1541890
__int64 UFG::_dynamic_initializer_for__sym_Sync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Sync01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_Sync01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_Sync01__);
}

// File Line: 3148
// RVA: 0x1541850
__int64 UFG::_dynamic_initializer_for__sym_Direction__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Direction", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_Direction, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_Direction__);
}

// File Line: 3156
// RVA: 0x4DE200
char __fastcall UFG::TSCharacter::Coro_sync_to_target(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectCVBase *m_pPointer; // rdi
  int v5; // r15d
  float mBlendTime; // xmm1_4
  float v8; // xmm7_4
  float weight; // xmm6_4
  char v10; // bp
  UFG::SimComponent *m_pComponent; // r14
  UFG::CharacterAnimationComponent *v12; // rax
  UFG::CharacterAnimationComponent *v13; // rsi
  __int64 v14; // rax
  UFG::TransformNodeComponent *v15; // r14
  Creature *mCreature; // rdi
  int BoneID; // r12d
  float v18; // xmm0_4

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    return 1;
  v5 = -1;
  if ( !pScope->i_update_count )
  {
    if ( (unsigned int)UFG::qStringCompare(
                         *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         "POI_Use",
                         -1) )
      return 1;
    this->mBlendTime = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
  }
  mBlendTime = this->mBlendTime;
  v8 = UFG::Metrics::msRealTimeDelta_Accurate;
  if ( mBlendTime <= 0.0000099999997 )
    weight = *(float *)&FLOAT_1_0;
  else
    weight = UFG::Metrics::msRealTimeDelta_Accurate / mBlendTime;
  v10 = 0;
  if ( weight > 0.99980003 )
  {
    weight = *(float *)&FLOAT_1_0;
    v10 = 1;
  }
  m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
  v13 = v12;
  if ( m_pComponent )
  {
    if ( v12 )
    {
      v14 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 34i64)
                      + *(_QWORD *)&m_pComponent[1].m_TypeUID
                      + 40);
      if ( v14 )
      {
        v15 = *(UFG::TransformNodeComponent **)(v14 + 88);
        mCreature = v13->mCreature;
        if ( v15 )
        {
          if ( mCreature )
          {
            if ( mCreature->mPose.mRigHandle.mData )
              BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::sym_Sync01.mUID);
            else
              BoneID = -1;
            if ( mCreature->mPose.mRigHandle.mData )
              v5 = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, UFG::sym_Direction.mUID);
            UFG::TransformNodeComponent::UpdateWorldTransform(v15);
            Creature::Attach(mCreature, BoneID, v5, &v15->mWorldTransform, weight);
          }
        }
      }
    }
  }
  v18 = this->mBlendTime;
  if ( v18 > 0.0 )
    this->mBlendTime = v18 - v8;
  if ( this->mBlendTime <= 0.0 )
    this->mBlendTime = 0.0;
  if ( v10 )
  {
    if ( v13 )
      Creature::MakeUpright(v13->mCreature, 0.0);
  }
  return v10;
}

// File Line: 3245
// RVA: 0x4DE100
bool __fastcall UFG::TSCharacter::Coro_submit_action_request(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rdi
  SSInstance *v8; // rsi
  bool v9; // bp

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( !m_pPointer )
    return 1;
  if ( (m_pPointer->m_Flags & 0x4000) == 0 )
    return 1;
  m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return 1;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v8 = i_array_p[1]->i_data_p;
  v9 = i_array_p[2]->i_data_p->i_user_data != 0;
  if ( !pScope->i_update_count )
    UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(m_pSimComponent);
  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
         (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
  {
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
      *(const char **)i_data_p->i_user_data);
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
      *(const char **)v8->i_user_data);
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
      v9);
  }
  return ((__int64)this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev & 4) != 0;
}

// File Line: 3282
// RVA: 0x4DBC70
bool __fastcall UFG::TSCharacter::Coro_move_to_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v5; // dl
  UFG::NavComponent *m_pComponent; // r14
  bool v7; // r15
  float *v8; // rcx
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  bool v12; // zf
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // xmm2_4
  UFG::TransformNodeComponent *v16; // rbx
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  UFG::SimComponent *v24; // rbx
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float NaturalMovementSpeed; // xmm3_4
  UFG::qVector3 position; // [rsp+30h] [rbp-29h] BYREF
  UFG::qVector3 out; // [rsp+40h] [rbp-19h] BYREF
  UFG::HavokNavPosition npDestination; // [rsp+50h] [rbp-9h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  v5 = pScope->i_update_count == 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
    if ( m_pComponent )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64;
      if ( v5 )
      {
        this->mpMoveToActor = UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        this->mMoveToActorThreshold = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
        v8 = *(float **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64);
        v9 = v8[1];
        v10 = v8[2];
        this->mMoveToActorOffset.x = *v8;
        this->mMoveToActorOffset.y = v9;
        this->mMoveToActorOffset.z = v10;
        this->mMoveToActorIsLocal = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64;
      }
      m_pSimComponent = (UFG::TransformNodeComponent *)this->mpMoveToActor->mTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
      v12 = !this->mMoveToActorIsLocal;
      y = m_pSimComponent->mWorldTransform.v3.y;
      z = m_pSimComponent->mWorldTransform.v3.z;
      x = m_pSimComponent->mWorldTransform.v3.x;
      position.x = x;
      position.y = y;
      position.z = z;
      if ( v12 )
      {
        v22 = y + this->mMoveToActorOffset.y;
        v23 = z + this->mMoveToActorOffset.z;
        position.x = x + this->mMoveToActorOffset.x;
        position.y = v22;
        position.z = v23;
      }
      else
      {
        v16 = (UFG::TransformNodeComponent *)this->mpMoveToActor->mTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v16);
        v17 = this->mMoveToActorOffset.x;
        v18 = v17 * v16->mWorldTransform.v0.z;
        v19 = this->mMoveToActorOffset.y * v16->mWorldTransform.v1.z;
        v20 = this->mMoveToActorOffset.z * v16->mWorldTransform.v2.z;
        v21 = (float)((float)(v17 * v16->mWorldTransform.v0.y)
                    + (float)(this->mMoveToActorOffset.y * v16->mWorldTransform.v1.y))
            + (float)(this->mMoveToActorOffset.z * v16->mWorldTransform.v2.y);
        position.x = position.x
                   + (float)((float)((float)(this->mMoveToActorOffset.y * v16->mWorldTransform.v1.x)
                                   + (float)(this->mMoveToActorOffset.x * v16->mWorldTransform.v0.x))
                           + (float)(this->mMoveToActorOffset.z * v16->mWorldTransform.v2.x));
        position.z = position.z + (float)((float)(v18 + v19) + v20);
        position.y = position.y + v21;
      }
      if ( !UFG::PlaceOnGround(&out, &position, 0.0, 0.0) )
        out = position;
      UFG::TSCharacter::SetTarget(this, &out, this->mMoveToActorThreshold);
      v24 = this->mpTargetNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v24);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
      v25 = *((float *)&v24[2].m_BoundComponentHandles.mNode.mPrev + 1);
      v26 = *(float *)&v24[2].m_BoundComponentHandles.mNode.mNext;
      v27 = *(float *)&v24[2].m_BoundComponentHandles.mNode.mPrev;
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      npDestination.m_vPosition.y = v25;
      npDestination.m_vPosition.z = v26;
      npDestination.m_vPosition.x = v27;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(v24[2].m_BoundComponentHandles.mNode.mPrev),
                                                   (__m128)LODWORD(v24[2].m_BoundComponentHandles.mNode.mNext)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)HIDWORD(v24[2].m_BoundComponentHandles.mNode.mPrev),
                                                   (__m128)(unsigned int)FLOAT_1_0));
      NaturalMovementSpeed = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
      UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, AiGoal_Replace, NaturalMovementSpeed, 0.30000001);
      return UFG::TSCharacter::PathToTarget(this, pScope, 1, v7) != 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3353
// RVA: 0x4DC130
bool __fastcall UFG::TSCharacter::Coro_move_to_xform(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // r8
  float *v5; // rcx
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool mMoveToActorIsLocal; // r9
  __int64 v9; // rcx
  UFG::TransformNodeComponent *mTransNode; // rdx
  bool v11; // bl
  UFG::qVector3 offset; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( m_pPointer->m_Components.p[36].m_pComponent )
    {
      if ( !pScope->i_update_count )
      {
        this->mTransNode = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        this->mMoveToActorThreshold = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
        v5 = *(float **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64);
        v6 = v5[1];
        v7 = v5[2];
        this->mMoveToActorOffset.x = *v5;
        this->mMoveToActorOffset.y = v6;
        this->mMoveToActorOffset.z = v7;
        this->mMoveToActorIsLocal = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64;
      }
      mMoveToActorIsLocal = this->mMoveToActorIsLocal;
      v9 = *((_QWORD *)pScope->i_data.i_array_p + 5);
      mTransNode = this->mTransNode;
      offset.x = this->mMoveToActorOffset.x;
      offset.y = offset.x;
      offset.z = offset.x;
      v11 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 32i64) != 0i64;
      UFG::TSCharacter::SetTarget(this, mTransNode, &offset, mMoveToActorIsLocal, this->mMoveToActorThreshold);
      return UFG::TSCharacter::PathToTarget(this, pScope, 1, v11) != 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3401
// RVA: 0x4DC030
bool __fastcall UFG::TSCharacter::Coro_move_to_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  SSData **i_array_p; // rdx
  UFG::qVector3 *i_user_data; // rbx
  float v7; // xmm6_4
  float *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::qVector3 out; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( !pScope->i_update_count )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_user_data = (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data;
      v7 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      v8 = (float *)i_array_p[3]->i_data_p->i_user_data;
      v9 = v8[1] + i_user_data->y;
      v10 = v8[2] + i_user_data->z;
      i_user_data->x = *v8 + i_user_data->x;
      i_user_data->y = v9;
      i_user_data->z = v10;
      UFG::PlaceOnGround(&out, i_user_data, 0.0, 0.0);
      UFG::TSCharacter::SetTarget(this, i_user_data, v7);
    }
    return UFG::TSCharacter::PathToTarget(this, pScope, 1, 0) != 0;
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3450
// RVA: 0x4DC480
char __fastcall UFG::TSCharacter::Coro_path_to_target_type(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::SimComponent *m_pComponent; // r8
  __int64 v8; // rcx
  UFG::TransformNodeComponent *v9; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+70h] [rbp+10h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( pScope->i_update_count )
      return UFG::TSCharacter::PathToTarget(
               this,
               pScope,
               2,
               *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v5->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    if ( m_pComponent )
    {
      v8 = *(_QWORD *)(56i64
                     * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                     + *(_QWORD *)&m_pComponent[1].m_TypeUID
                     + 40);
      if ( v8 )
      {
        v9 = *(UFG::TransformNodeComponent **)(v8 + 88);
        if ( v9 )
        {
          UFG::TSCharacter::SetTarget(
            this,
            v9,
            *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64),
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64,
            *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
          v10 = pTrackEnumBinding.mPrev;
          mNext = pTrackEnumBinding.mNext;
          pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
          mNext->mPrev = v10;
          pTrackEnumBinding.mPrev = &pTrackEnumBinding;
          pTrackEnumBinding.mNext = &pTrackEnumBinding;
          return UFG::TSCharacter::PathToTarget(
                   this,
                   pScope,
                   2,
                   *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
        }
      }
    }
    v12 = pTrackEnumBinding.mPrev;
    v13 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
  }
  return 0;
}

// File Line: 3524
// RVA: 0x4DACC0
char __fastcall UFG::TSCharacter::Coro_follow_path_safe(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  bool v4; // r10
  SSData **i_array_p; // r9
  bool v6; // r8
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObject *v8; // rdx
  UFG::NavComponent *m_pComponent; // r14
  unsigned int i_user_data; // ebx
  SSInvokedCoroutine *i_obj_p; // rcx
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rcx
  __m128 x_low; // xmm2
  float v15; // xmm1_4
  float v16; // xmm8_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  __m128 v19; // xmm2
  __m128 v20; // xmm5
  float v21; // xmm1_4
  __m128 v22; // xmm10
  float v23; // xmm9_4
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  float v26; // xmm1_4
  float v27; // xmm9_4
  float v28; // xmm2_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  __m128 v31; // xmm5
  __m128 v32; // xmm11
  float v33; // xmm3_4
  UFG::qVector3 direction; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qVector3 position; // [rsp+48h] [rbp-90h] BYREF
  UFG::qMatrix44 v36[3]; // [rsp+58h] [rbp-80h] BYREF
  UFG::qSymbol symbol; // [rsp+128h] [rbp+50h] BYREF
  float elapsedTime; // [rsp+130h] [rbp+58h] BYREF
  int uid; // [rsp+138h] [rbp+60h] BYREF
  UFG::qSymbol *p_symbol; // [rsp+140h] [rbp+68h]

  v4 = pScope->i_update_count == 0;
  i_array_p = pScope->i_data.i_array_p;
  v6 = i_array_p[1]->i_data_p->i_user_data != 0;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    v8 = m_pPointer;
  else
    v8 = 0i64;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
      if ( m_pComponent )
      {
        if ( !v8 )
        {
          SSInvokedCoroutine::suspend(pScope);
          return 0;
        }
        i_user_data = (*i_array_p)->i_data_p->i_user_data;
        if ( v4 )
        {
          i_obj_p = this->mpNavigationThread.i_obj_p;
          if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p != pScope )
            ++i_obj_p->i_pending_count;
          this->mpNavigationThread.i_obj_p = pScope;
          this->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
          if ( v6 )
            this->mModeFlags |= 2u;
          else
            this->mModeFlags &= ~2u;
          BYTE1(this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) &= ~0x80u;
          if ( !UFG::AIScriptInterfaceComponent::GiveCommand(
                  (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
                  eSCRIPT_COMMAND_FOLLOW_SCRIPTED_PATH,
                  this->mSpeed) )
            return 0;
          p_symbol = &symbol;
          symbol.mUID = i_user_data;
          m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
          goto LABEL_40;
        }
        UFG::NavComponent::PreserveDestination(m_pComponent);
        if ( SBYTE1(this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) >= 0 )
          return 0;
        if ( !UFG::NavComponent::IsAtDestination(m_pComponent) )
        {
          uid = -1;
          elapsedTime = FLOAT_N1_0;
          if ( UFG::NavComponent::GetCurrGoalPointInfo(m_pComponent, &position, &direction, &elapsedTime, &uid)
            && elapsedTime > *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) )
          {
            UFG::NavComponent::ForceGoalPointAdvance(m_pComponent);
            x_low = (__m128)LODWORD(direction.x);
            x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                      + (float)(direction.y * direction.y))
                              + (float)(direction.z * direction.z);
            if ( x_low.m128_f32[0] == 0.0 )
              v15 = 0.0;
            else
              v15 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
            v16 = v15 * direction.z;
            v17 = direction.y * v15;
            v18 = direction.x * v15;
            v19 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
            v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0])
                                    + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                            + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
            if ( v19.m128_f32[0] == 0.0 )
            {
              v20 = 0i64;
            }
            else
            {
              v20 = (__m128)(unsigned int)FLOAT_1_0;
              v20.m128_f32[0] = 1.0 / _mm_sqrt_ps(v19).m128_f32[0];
            }
            v21 = v20.m128_f32[0] * UFG::qVector3::msDirUp.z;
            v24 = v20;
            v24.m128_f32[0] = v20.m128_f32[0] * UFG::qVector3::msDirUp.y;
            v20.m128_f32[0] = v20.m128_f32[0] * UFG::qVector3::msDirUp.x;
            v22 = v20;
            v22.m128_f32[0] = (float)(v20.m128_f32[0] * v17) - (float)(v18 * v24.m128_f32[0]);
            v23 = (float)(v18 * v21) - (float)(v20.m128_f32[0] * v16);
            v24.m128_f32[0] = (float)(v24.m128_f32[0] * v16) - (float)(v21 * v17);
            v25 = v24;
            v25.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v23 * v23))
                            + (float)(v22.m128_f32[0] * v22.m128_f32[0]);
            if ( v25.m128_f32[0] == 0.0 )
              v26 = 0.0;
            else
              v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
            v22.m128_f32[0] = v22.m128_f32[0] * v26;
            v27 = v23 * v26;
            v28 = v24.m128_f32[0] * v26;
            v29 = (float)(v27 * v18) - (float)(v28 * v17);
            v30 = (float)(v28 * v16) - (float)(v22.m128_f32[0] * v18);
            v31 = v22;
            v31.m128_f32[0] = (float)(v22.m128_f32[0] * v17) - (float)(v27 * v16);
            v32 = v31;
            v32.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30))
                            + (float)(v29 * v29);
            if ( v32.m128_f32[0] == 0.0 )
              v33 = 0.0;
            else
              v33 = 1.0 / _mm_sqrt_ps(v32).m128_f32[0];
            LODWORD(v36[0].v1.z) = v22.m128_i32[0];
            v36[0].v1.w = 0.0;
            v36[0].v2.x = v31.m128_f32[0] * v33;
            v36[0].v2.y = v33 * v30;
            v36[0].v0.x = v33 * v29;
            v36[0].v0.y = 0.0;
            *(UFG::qVector3 *)&v36[0].v0.z = position;
            v36[0].v1.y = 1.0;
            UFG::TSActor::TeleportToTransform(this, v36);
          }
          if ( !UFG::AIScriptInterfaceComponent::GiveCommand(
                  (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
                  eSCRIPT_COMMAND_FOLLOW_SCRIPTED_PATH,
                  this->mSpeed) )
            return 0;
          p_symbol = &symbol;
          symbol.mUID = i_user_data;
          m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
LABEL_40:
          UFG::AIScriptInterfaceComponent::AddArgument(m_pSimComponent, &symbol.mUID);
          return 0;
        }
        BYTE1(this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) &= ~0x80u;
        UFG::TSCharacter::NavigationScriptFinish(this, pScope);
      }
    }
  }
  return 1;
}

// File Line: 3628
// RVA: 0x4DC2D0
char __fastcall UFG::TSCharacter::Coro_path_to_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::TSActor *ArgByNameOrInstance; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( !pScope->i_update_count )
    {
      ArgByNameOrInstance = UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
      UFG::TSCharacter::SetTarget(
        this,
        (UFG::TransformNodeComponent *)ArgByNameOrInstance->mTransformNodeComponent.m_pSimComponent,
        *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64),
        *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64,
        *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
    }
    return UFG::TSCharacter::PathToTarget(this, pScope, 2, 0);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3660
// RVA: 0x4DC6A0
char __fastcall UFG::TSCharacter::Coro_path_to_xform(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  SSData **i_array_p; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( !pScope->i_update_count )
    {
      i_array_p = pScope->i_data.i_array_p;
      UFG::TSCharacter::SetTarget(
        this,
        (UFG::TransformNodeComponent *)(*i_array_p)->i_data_p->i_user_data,
        (UFG::qVector3 *)i_array_p[3]->i_data_p->i_user_data,
        i_array_p[4]->i_data_p->i_user_data != 0,
        *(float *)&i_array_p[1]->i_data_p->i_user_data);
    }
    return UFG::TSCharacter::PathToTarget(
             this,
             pScope,
             2,
             *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3692
// RVA: 0x4DC390
char __fastcall UFG::TSCharacter::Coro_path_to_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *m_pPointer; // rax
  SSData **i_array_p; // r8
  float *i_user_data; // rdx
  float *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-18h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    if ( !pScope->i_update_count )
    {
      i_array_p = pScope->i_data.i_array_p;
      i_user_data = (float *)(*i_array_p)->i_data_p->i_user_data;
      v7 = (float *)i_array_p[3]->i_data_p->i_user_data;
      v8 = v7[1] + i_user_data[1];
      pos.x = *v7 + *i_user_data;
      v9 = v7[2];
      pos.y = v8;
      v10 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      pos.z = v9 + i_user_data[2];
      UFG::TSCharacter::SetTarget(this, &pos, v10);
    }
    return UFG::TSCharacter::PathToTarget(
             this,
             pScope,
             2,
             *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    return 0;
  }
}

// File Line: 3723
// RVA: 0x50A6E0
void __fastcall UFG::TSCharacter::Mthd_set_speed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  this->mSpeed = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 3733
// RVA: 0x4FEBD0
void __fastcall UFG::TSCharacter::Mthd_get_speed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  unsigned int v5; // xmm0_4
  UFG::CharacterPhysicsComponent *m_pComponent; // rcx
  __m128 x_low; // xmm2
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    v5 = 0;
    if ( m_pPointer )
    {
      m_pComponent = (UFG::CharacterPhysicsComponent *)m_pPointer->m_Components.p[27].m_pComponent;
      if ( m_pComponent )
      {
        UFG::CharacterPhysicsComponent::GetVelocity(m_pComponent, &result);
        x_low = (__m128)LODWORD(result.x);
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                          + (float)(result.z * result.z);
        v5 = _mm_sqrt_ps(x_low).m128_u32[0];
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, v5);
  }
}

// File Line: 3761
// RVA: 0x508760
void __fastcall UFG::TSCharacter::Mthd_set_ignore_ambient_stimuli(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x400ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x400ui64;
      }
    }
  }
}

// File Line: 3776
// RVA: 0x4F4970
void __fastcall UFG::TSCharacter::Mthd_allow_jog(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 1ui64;
        else
          v5->mBooleans.mBits[0] &= ~1ui64;
      }
    }
  }
}

// File Line: 3796
// RVA: 0x502500
void __fastcall UFG::TSCharacter::Mthd_is_jog_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 1) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3819
// RVA: 0x4F4A30
void __fastcall UFG::TSCharacter::Mthd_allow_sprint(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 2ui64;
        else
          v5->mBooleans.mBits[0] &= ~2ui64;
      }
    }
  }
}

// File Line: 3839
// RVA: 0x503240
void __fastcall UFG::TSCharacter::Mthd_is_sprint_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 2) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3862
// RVA: 0x4F4850
void __fastcall UFG::TSCharacter::Mthd_allow_combat_prop_use(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 4ui64;
        else
          v5->mBooleans.mBits[0] &= ~4ui64;
      }
    }
  }
}

// File Line: 3881
// RVA: 0x5012C0
void __fastcall UFG::TSCharacter::Mthd_is_combat_prop_use_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 4) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3903
// RVA: 0x4F47F0
void __fastcall UFG::TSCharacter::Mthd_allow_action_hijack(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 8ui64;
        else
          v5->mBooleans.mBits[0] &= ~8ui64;
      }
    }
  }
}

// File Line: 3917
// RVA: 0x500820
void __fastcall UFG::TSCharacter::Mthd_is_action_hijack_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 8) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3932
// RVA: 0x4F4AF0
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_exit(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x10ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x10ui64;
      }
    }
  }
}

// File Line: 3946
// RVA: 0x503DA0
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_exit_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 0x10) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3961
// RVA: 0x4F4A90
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_eject(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x20ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x20ui64;
      }
    }
  }
}

// File Line: 3975
// RVA: 0x503D40
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_eject_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 0x20) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3990
// RVA: 0x4F4B50
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_shooting(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x40ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x40ui64;
      }
    }
  }
}

// File Line: 4004
// RVA: 0x503E00
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_shooting_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 0x40) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4019
// RVA: 0x4F49D0
void __fastcall UFG::TSCharacter::Mthd_allow_sneak_attack(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x80ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x80ui64;
      }
    }
  }
}

// File Line: 4033
// RVA: 0x5031E0
void __fastcall UFG::TSCharacter::Mthd_is_sneak_attack_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && SLOBYTE(v5->mBooleans.mBits[0]) < 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4048
// RVA: 0x4F4910
void __fastcall UFG::TSCharacter::Mthd_allow_hostage_release(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x100ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x100ui64;
      }
    }
  }
}

// File Line: 4062
// RVA: 0x501980
void __fastcall UFG::TSCharacter::Mthd_is_hostage_release_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 0x100) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4077
// RVA: 0x4F48B0
void __fastcall UFG::TSCharacter::Mthd_allow_equip_stowed_weapon(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x200ui64;
        else
          v5->mBooleans.mBits[0] &= ~0x200ui64;
      }
    }
  }
}

// File Line: 4091
// RVA: 0x501370
void __fastcall UFG::TSCharacter::Mthd_is_equip_stowed_weapon_allowed(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer)) != 0i64
      && (v5->mBooleans.mBits[0] & 0x200) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4106
// RVA: 0x4F3770
void __fastcall UFG::TSCharacter::Mthd_action_request_disable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v5; // rbx
  unsigned int action_request; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        {
          if ( Intention::GetActionRequest(
                 *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                 &action_request) )
          {
            v5->m_ActionRequestMask.mBits[(__int64)(int)action_request >> 6] &= ~(1i64 << (action_request & 0x3F));
          }
        }
      }
    }
  }
}

// File Line: 4131
// RVA: 0x5084B0
void __fastcall UFG::TSCharacter::Mthd_set_free_aim_intention_xform(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::AimingPlayerComponent *v5; // rax
  UFG::TransformNodeComponent *m_pComponent; // rdi
  UFG::AimingPlayerComponent *v7; // rsi
  unsigned __int64 i_user_data; // rbx
  float v9; // xmm2_4
  float v10; // xmm5_4
  __m128 v11; // xmm6
  float v12; // xmm3_4
  __m128 v13; // xmm4
  UFG::qVector3 vDirection; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>((UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer);
      m_pComponent = (UFG::TransformNodeComponent *)m_pPointer->m_Components.p[2].m_pComponent;
      v7 = v5;
      if ( v5 )
      {
        if ( m_pComponent )
        {
          i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)i_user_data);
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
          v11 = (__m128)*(unsigned int *)(i_user_data + 180);
          v9 = 0.0;
          v10 = *(float *)(i_user_data + 176) - m_pComponent->mWorldTransform.v3.x;
          v11.m128_f32[0] = v11.m128_f32[0] - m_pComponent->mWorldTransform.v3.y;
          v12 = *(float *)(i_user_data + 184) - m_pComponent->mWorldTransform.v3.z;
          v13 = v11;
          v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10))
                          + (float)(v12 * v12);
          if ( v13.m128_f32[0] != 0.0 )
            v9 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
          vDirection.z = v12 * v9;
          vDirection.x = v9 * v10;
          vDirection.y = v9 * v11.m128_f32[0];
          UFG::AimingPlayerComponent::SetFreeAimIntention(v7, &vDirection);
        }
      }
    }
  }
}

// File Line: 4151
// RVA: 0x4F8E30
void __fastcall UFG::TSCharacter::Mthd_enable_pathing_on_material(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::NavComponent *m_pComponent; // rdi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  bool v7; // si
  hkaiUFGMaterials v8; // edx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
      if ( m_pComponent )
      {
        i_array_p = pScope->i_data.i_array_p;
        i_data_p = (*i_array_p)->i_data_p;
        v7 = i_array_p[1]->i_data_p->i_user_data != 0;
        if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, "generic", -1) )
        {
          if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, "road", -1) )
          {
            if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, "sidewalk", -1) )
            {
              if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, "grass", -1) )
              {
                if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)i_data_p->i_user_data, "water", -1) )
                  return;
                v8 = hkaiMaterial_Water;
              }
              else
              {
                v8 = hkaiMaterial_Grass;
              }
            }
            else
            {
              v8 = hkaiMaterial_Sidewalk;
            }
          }
          else
          {
            v8 = hkaiMaterial_Road;
          }
        }
        else
        {
          v8 = hkaiMaterial_Generic;
        }
        UFG::NavComponent::EnablePathingOnMaterial(m_pComponent, v8, v7);
      }
    }
  }
}

// File Line: 4185
// RVA: 0x4F9160
void __fastcall UFG::TSCharacter::Mthd_enable_sloppy_freerunning(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // r8

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
    if ( m_pComponent )
      LOBYTE(m_pComponent[2].m_BoundComponentHandles.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 4200
// RVA: 0x4F8AF0
void __fastcall UFG::TSCharacter::Mthd_enable_freerunning(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // r8
  int vfptr; // eax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[36].m_pComponent;
      if ( m_pComponent )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        {
          LODWORD(m_pComponent[3].vfptr) |= 1u;
        }
        else
        {
          vfptr = (int)m_pComponent[3].vfptr;
          LOBYTE(m_pComponent[3].vfptr) = 0;
          LODWORD(m_pComponent[3].vfptr) |= vfptr & 0xFE;
        }
      }
    }
  }
}

// File Line: 4225
// RVA: 0x4F3800
void __fastcall UFG::TSCharacter::Mthd_action_request_enable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v5; // rbx
  unsigned int action_request; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
      if ( v5 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        {
          if ( Intention::GetActionRequest(
                 *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                 &action_request) )
          {
            v5->m_ActionRequestMask.mBits[(__int64)(int)action_request >> 6] |= 1i64 << (action_request & 0x3F);
          }
        }
      }
    }
  }
}

// File Line: 4251
// RVA: 0x4F3890
void __fastcall UFG::TSCharacter::Mthd_action_request_enable_all(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax

  m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pPointer);
    if ( v4 )
    {
      v4->m_ActionRequestMask.mBits[0] = -1i64;
      v4->m_ActionRequestMask.mBits[1] = -1i64;
      v4->m_ActionRequestMask.mBits[2] = -1i64;
      v4->m_ActionRequestMask.mBits[3] = -1i64;
      v4->m_ActionRequestMask.mBits[4] = -1i64;
      v4->m_ActionRequestMask.mBits[5] = -1i64;
      v4->m_ActionRequestMask.mBits[6] = -1i64;
      v4->m_ActionRequestMask.mBits[7] = -1i64;
      v4->m_ActionRequestMask.mBits[8] = -1i64;
    }
  }
}

// File Line: 4268
// RVA: 0x50EEF0
char __fastcall UFG::TSCharacter::PathToTarget(
        UFG::TSCharacter *this,
        SSInvokedCoroutine *pScope,
        UFG::eScriptCommand command,
        bool terminateOnFail)
{
  bool v6; // dl
  SSInvokedCoroutine *i_obj_p; // rcx
  UFG::SimObject *m_pPointer; // rcx
  UFG::AiPathGoalMode v11; // esi
  UFG::NavComponent *m_pComponent; // rbp
  UFG::TransformNodeComponent *v13; // rbx
  float y; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
  float fDestinationTolerance; // [rsp+20h] [rbp-68h]
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-58h] BYREF

  v6 = pScope->i_update_count == 0;
  if ( v6 )
  {
    i_obj_p = this->mpNavigationThread.i_obj_p;
    if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p != pScope )
      ++i_obj_p->i_pending_count;
    this->mpNavigationThread.i_obj_p = pScope;
    this->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
  }
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v11 = AiGoal_Replace;
    if ( (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    m_pComponent = (UFG::NavComponent *)m_pPointer->m_Components.p[36].m_pComponent;
  }
  else
  {
    v11 = AiGoal_Replace;
    m_pComponent = 0i64;
  }
  if ( this->mAIScriptInterfaceComponent.m_pSimComponent && m_pComponent && this->mpTargetNode.m_pPointer )
  {
    if ( v6 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64) )
        this->mModeFlags |= 2u;
      else
        this->mModeFlags &= ~2u;
LABEL_25:
      v13 = (UFG::TransformNodeComponent *)this->mpTargetNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
      LOBYTE(v11) = command == eSCRIPT_COMMAND_MOVE_DIRECTLY_TO_POSITION;
      y = v13->mWorldTransform.v3.y;
      z = v13->mWorldTransform.v3.z;
      x = v13->mWorldTransform.v3.x;
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
      npDestination.m_vPosition.x = x;
      npDestination.m_vPosition.y = y;
      npDestination.m_vPosition.z = z;
      fDestinationTolerance = this->mTargetThreshold;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.x),
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(m_pComponent, &npDestination, v11, -1.0, fDestinationTolerance);
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
        command,
        this->mSpeed);
      return 0;
    }
    if ( UFG::TSCharacter::IsAtTarget(this) )
    {
      UFG::TSCharacter::NavigationScriptFinish(this, pScope);
    }
    else if ( !terminateOnFail || !UFG::NavComponent::IsDestinationUnreachable(m_pComponent) )
    {
      goto LABEL_25;
    }
  }
  else if ( this->mpNavigationThread.i_obj_p == pScope )
  {
    this->mpNavigationThread.i_obj_p = 0i64;
    this->mpNavigationThread.i_ptr_id = 0;
  }
  return 1;
}

// File Line: 4327
// RVA: 0x4DD110
char __fastcall UFG::TSCharacter::Coro_rotate_dir(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *i_obj_p; // rcx
  float v5; // xmm2_4
  UFG::qVector3 *i_user_data; // rdi
  float y; // xmm4_4
  float z; // xmm5_4
  __m128 x_low; // xmm3
  UFG::SimObject *m_pPointer; // rcx
  float v11; // xmm1_4
  UFG::qVector3 direction; // [rsp+20h] [rbp-18h] BYREF

  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    v5 = 0.0;
    i_user_data = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    y = i_user_data->y;
    z = i_user_data->z;
    x_low = (__m128)LODWORD(i_user_data->x);
    x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( x_low.m128_f32[0] != 0.0 )
      v5 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
    m_pPointer = this->mpSimObj.m_pPointer;
    v11 = v5 * i_user_data->x;
    direction.z = v5 * z;
    direction.y = v5 * y;
    direction.x = v11;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( UFG::IsFacingDirection(m_pPointer, &direction, -1.0) )
    {
      return 1;
    }
    else
    {
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        i_user_data);
      return 0;
    }
  }
  else
  {
    i_obj_p = this->mpNavigationThread.i_obj_p;
    if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p != pScope )
      ++i_obj_p->i_pending_count;
    this->mpNavigationThread.i_obj_p = pScope;
    this->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    return 0;
  }
}

// File Line: 4361
// RVA: 0x4DD250
char __fastcall UFG::TSCharacter::Coro_rotate_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *i_obj_p; // rcx
  UFG::SimObject *m_pPointer; // rcx
  UFG::qVector3 *i_user_data; // rdi

  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    i_user_data = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      if ( UFG::IsFacingPosition(m_pPointer, i_user_data, -1.0) )
        return 1;
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        i_user_data);
    }
    return 0;
  }
  else
  {
    i_obj_p = this->mpNavigationThread.i_obj_p;
    if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p != pScope )
      ++i_obj_p->i_pending_count;
    this->mpNavigationThread.i_obj_p = pScope;
    this->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    return 0;
  }
}

// File Line: 4397
// RVA: 0x4DD030
char __fastcall UFG::TSCharacter::Coro_rotate_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *i_obj_p; // rcx
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::SimObject *m_pPointer; // rcx

  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    m_pSimComponent = UFG::TSActor::GetArgByNameOrInstance(pScope, 0)->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( UFG::IsFacingPosition(m_pPointer, (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles, -1.0) )
    {
      return 1;
    }
    else
    {
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        (UFG::TransformNodeComponent *)m_pSimComponent);
      return 0;
    }
  }
  else
  {
    i_obj_p = this->mpNavigationThread.i_obj_p;
    if ( i_obj_p && this->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p != pScope )
      ++i_obj_p->i_pending_count;
    this->mpNavigationThread.i_obj_p = pScope;
    this->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    return 0;
  }
}

// File Line: 4429
// RVA: 0x4E08F0
void __fastcall UFG::TSCharacter::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectCharacter *mNext; // rbx
  __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rdi
  SSActorClass *i_class_p; // rcx
  SSClass *i_superclass_p; // rcx
  UFG::TSCharacter *Actor; // rdi
  SSInvokedCoroutine *i_obj_p; // rax
  UFG::ProgressionTracker *v8; // rax
  UFG::CopSystem *v9; // rax
  unsigned int v10; // edx
  __int16 v11; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  mNext = (UFG::SimObjectCharacter *)thisEvent[1].mNext;
  if ( mNext )
  {
    m_Flags = mNext->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[3].m_pComponent;
      else
        m_pComponent = (UFG::TSActorComponent *)((m_Flags & 0x1000) != 0
                                               ? mNext->m_Components.p[2].m_pComponent
                                               : UFG::SimObject::GetComponentOfType(
                                                   mNext,
                                                   UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)mNext->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent )
    {
      i_class_p = (SSActorClass *)UFG::TSActorComponent::GetActor(m_pComponent)->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == i_class_p
        || (i_superclass_p = i_class_p->i_superclass_p) != 0i64
        && SSClass::is_class(i_superclass_p, UFG::SkookumMgr::mspCharacterClass) )
      {
        Actor = (UFG::TSCharacter *)UFG::TSActorComponent::GetActor(m_pComponent);
        UFG::TSCharacter::ClearTarget(Actor);
        i_obj_p = Actor->mpNavigationThread.i_obj_p;
        if ( i_obj_p && Actor->mpNavigationThread.i_ptr_id == i_obj_p->i_ptr_id )
          ++i_obj_p->i_pending_count;
        Actor->mpNavigationThread.i_obj_p = 0i64;
        Actor->mpNavigationThread.i_ptr_id = 0;
        if ( mNext == UFG::GetLocalPlayer() )
        {
          v8 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetRestoreType(v8, RestoreType_Hospital, 1);
          UFG::MissionFailConditionComponent::FailObject(mNext, &qSymbol_DeathFailCaption);
          v9 = UFG::CopSystem::Instance();
          v10 = UI_HASH_CLEANUPMINIGAME_15;
          v9->mStats.mFinishReason = eFinishReason_Death;
          UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v10, 0xFFFFFFFF);
        }
        else
        {
          v11 = mNext->m_Flags;
          if ( (v11 & 0x4000) != 0 )
          {
            ComponentOfTypeHK = mNext->m_Components.p[8].m_pComponent;
          }
          else if ( v11 >= 0 )
          {
            if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    mNext,
                                    UFG::MissionFailConditionComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    mNext,
                                    UFG::MissionFailConditionComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = mNext->m_Components.p[8].m_pComponent;
          }
          if ( ComponentOfTypeHK
            && (BYTE5(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev)
             || BYTE6(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mPrev)) )
          {
            UFG::MissionFailConditionComponent::FailObject(mNext, &qSymbol_DeathFailCaption);
          }
        }
      }
    }
  }
}

// File Line: 4476
// RVA: 0x50B9D0
void __fastcall UFG::TSCharacter::Mthd_standing_get(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned int FaceLevel; // ebx
  UFG::SimObjectCharacter *m_pPointer; // rdi
  UFG::GameStatTracker *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  FaceLevel = 0;
  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer == UFG::GetLocalPlayer() )
    {
      v7 = UFG::GameStatTracker::Instance();
      FaceLevel = UFG::GameStatTracker::GetFaceLevel(v7);
    }
    else
    {
      v8 = this->mpSimObj.m_pPointer;
      if ( v8 )
      {
        if ( (v8->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v8->m_Components.p[45].m_pComponent;
          if ( m_pComponent )
            FaceLevel = (unsigned int)m_pComponent[3].m_pSimObject;
        }
      }
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, FaceLevel);
}

// File Line: 4502
// RVA: 0x50BAA0
void __fastcall UFG::TSCharacter::Mthd_standing_get_targets(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned int FaceLevel; // edi
  UFG::SimObject *m_pPointer; // rax
  UFG::qSymbol *v7; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimObjectCharacter *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  FaceLevel = 0;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    v7 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v7->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gTargetTypeEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v9 = this->mpSimObj.m_pPointer;
      if ( v9 )
      {
        if ( (v9->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = v9->m_Components.p[20].m_pComponent;
          if ( m_pComponent )
          {
            v11 = *(UFG::SimObjectCharacter **)(56i64
                                              * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                                   + pTrackEnumBinding.m_EnumValue
                                                                   + 8i64)
                                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                              + 40);
            if ( v11 )
            {
              if ( v11 == UFG::GetLocalPlayer() )
              {
                v12 = UFG::GameStatTracker::Instance();
                FaceLevel = UFG::GameStatTracker::GetFaceLevel(v12);
              }
              else
              {
                m_Flags = v11->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  ComponentOfTypeHK = v11->m_Components.p[45].m_pComponent;
                }
                else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                {
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v11, UFG::FaceActionComponent::_TypeUID);
                }
                else
                {
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v11, UFG::FaceActionComponent::_TypeUID);
                }
                if ( ComponentOfTypeHK )
                  FaceLevel = (unsigned int)ComponentOfTypeHK[3].m_pSimObject;
              }
            }
          }
        }
      }
    }
    v15 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v15;
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, FaceLevel);
}

// File Line: 4556
// RVA: 0x502380
void __fastcall UFG::TSCharacter::Mthd_is_in_water(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // dl

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
        v4 = UFG::SimObjectUtility::IsInWater(m_pPointer);
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 4574
// RVA: 0x50AEC0
void __fastcall UFG::TSCharacter::Mthd_set_target_to_choose_targets_near(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSData *v5; // rax
  float *p_i_user_data; // rbp
  float *v7; // r14
  const char ***v8; // rsi
  UFG::eTargetTypeEnum v9; // edi
  const char **v10; // rbx
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rax
  float v12; // xmm1_4

  i_array_p = pScope->i_data.i_array_p;
  v5 = i_array_p[2];
  p_i_user_data = (float *)&i_array_p[1]->i_data_p->i_user_data;
  v7 = (float *)&v5->i_data_p->i_user_data;
  v8 = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64
    && i_array_p[1]->i_data_p != (SSInstance *)-32i64
    && v5->i_data_p != (SSInstance *)-32i64
    && this->mActiveAIEntityComponent.m_pSimComponent )
  {
    v9 = eTARGET_TYPE_INVALID;
    v10 = UFG::TargetTypeEnumNames;
    do
    {
      if ( !(unsigned int)UFG::qStringCompare(**v8, *v10, -1) )
        break;
      ++v10;
      ++v9;
    }
    while ( (__int64)v10 < (__int64)UFG::AttackPhaseEnumNames );
    if ( v9 < NUM_TARGET_TYPES )
    {
      m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
      v12 = *v7;
      m_pSimComponent->m_MaxDistanceFromTargetToStayNear = *p_i_user_data;
      m_pSimComponent->m_MaxDistanceFromTargetToStayNearHysteresis = v12;
      m_pSimComponent->m_TargetToStayNear = v9;
    }
  }
}

// File Line: 4599
// RVA: 0x5087C0
void __fastcall UFG::TSCharacter::Mthd_set_interacting_with_vehicle_heuristic(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    BYTE2(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE2(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
}

// File Line: 4611
// RVA: 0x507210
void __fastcall UFG::TSCharacter::Mthd_set_attack_timer(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::HitReactionComponent *m_pComponent; // rcx

  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::HitReactionComponent *)m_pPointer->m_Components.p[15].m_pComponent;
        if ( m_pComponent )
          m_pComponent->mStateVariables.mAttackTimer = *(float *)&(*i_array_p)->i_data_p->i_user_data;
      }
    }
  }
}

// File Line: 4630
// RVA: 0x4F8730
void __fastcall UFG::TSCharacter::Mthd_distance_target(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  float distance; // [rsp+40h] [rbp+18h] BYREF
  float distance_2d; // [rsp+48h] [rbp+20h] BYREF

  if ( ppResult )
  {
    distance = 0.0;
    if ( !UFG::TSCharacter::GetDistanceToTarget(this, pScope, &distance, &distance_2d) )
      distance = 0.0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(distance));
  }
}

// File Line: 4644
// RVA: 0x4F8790
void __fastcall UFG::TSCharacter::Mthd_distance_target_2d(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  float distance_2d; // [rsp+40h] [rbp+18h] BYREF
  float distance; // [rsp+48h] [rbp+20h] BYREF

  if ( ppResult )
  {
    distance_2d = 0.0;
    if ( UFG::TSCharacter::GetDistanceToTarget(this, pScope, &distance, &distance_2d) )
    {
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(distance_2d));
    }
    else
    {
      distance_2d = 0.0;
      *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, 0i64);
    }
  }
}

// File Line: 4666
// RVA: 0x507BC0
void __fastcall UFG::TSCharacter::Mthd_set_combat_region(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::AIEntityComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::AIEntityComponent *)m_pPointer->m_Components.p[22].m_pComponent;
    if ( m_pComponent )
      UFG::AIEntityComponent::SetCombatRegion(
        m_pComponent,
        (UFG::CombatRegion *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4679
// RVA: 0x507800
void __fastcall UFG::TSCharacter::Mthd_set_can_gain_attack_rights(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::ActiveAIEntityComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::ActiveAIEntityComponent *)m_pPointer->m_Components.p[5].m_pComponent;
    if ( m_pComponent )
      BYTE1(m_pComponent->m_pDesiredTarget[6].mNext) ^= (BYTE1(m_pComponent->m_pDesiredTarget[6].mNext) ^ (16 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 0x10;
  }
}

// File Line: 4693
// RVA: 0x508260
void __fastcall UFG::TSCharacter::Mthd_set_fake_has_hostage(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[5].m_pComponent;
    if ( m_pComponent )
      BYTE1(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE1(m_pComponent[32].m_BoundComponentHandles.mNode.mPrev) ^ (32 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 0x20;
  }
}

// File Line: 4707
// RVA: 0x4FBCB0
void __fastcall UFG::TSCharacter::Mthd_get_can_gain_attack_rights(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::AttackRightsComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::AttackRightsComponent *)m_pPointer->m_Components.p[5].m_pComponent;
        if ( m_pComponent )
          *ppResult = SSBoolean::pool_new((BYTE1(m_pComponent->m_pAttackSlot[0][1][19].m_pPointer) & 0x10) != 0);
      }
    }
  }
}

// File Line: 4723
// RVA: 0x4E10D0
char __fastcall UFG::TSCharacter::GetDistanceToTarget(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        float *distance,
        float *distance_2d)
{
  UFG::TransformNodeComponent *v7; // rbx
  char v8; // si
  UFG::SimObject *m_pPointer; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  __int64 m_EnumValue; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  UFG::SimObject *v14; // rcx
  UFG::SimComponent *m_pComponent; // r8
  __int64 v16; // rcx
  UFG::SimComponent *m_pSimComponent; // rdi
  float v18; // xmm6_4
  __m128 mPrev_high; // xmm8
  __m128 mNext_low; // xmm7
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-58h] BYREF
  UFG::qSymbol result; // [rsp+A0h] [rbp+20h] BYREF

  v7 = 0i64;
  *distance = 0.0;
  *distance_2d = 0.0;
  v8 = 0;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
    return 0;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gTargetTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v12 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v12;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  if ( (unsigned int)m_EnumValue < 0x5B )
  {
    v14 = this->mpSimObj.m_pPointer;
    if ( v14 )
    {
      if ( (v14->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v14->m_Components.p[20].m_pComponent;
        if ( m_pComponent )
        {
          v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + m_EnumValue + 8)
                          + *(_QWORD *)&m_pComponent[1].m_TypeUID
                          + 40);
          if ( v16 )
            v7 = *(UFG::TransformNodeComponent **)(v16 + 88);
          if ( v7 )
          {
            m_pSimComponent = this->mTransformNodeComponent.m_pSimComponent;
            if ( m_pSimComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
              v18 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
              mPrev_high = (__m128)HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
              mNext_low = (__m128)LODWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext);
              UFG::TransformNodeComponent::UpdateWorldTransform(v7);
              mPrev_high.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] - v7->mWorldTransform.v3.y)
                                             * (float)(mPrev_high.m128_f32[0] - v7->mWorldTransform.v3.y))
                                     + (float)((float)(v18 - v7->mWorldTransform.v3.x)
                                             * (float)(v18 - v7->mWorldTransform.v3.x));
              mNext_low.m128_f32[0] = (float)((float)(mNext_low.m128_f32[0] - v7->mWorldTransform.v3.z)
                                            * (float)(mNext_low.m128_f32[0] - v7->mWorldTransform.v3.z))
                                    + mPrev_high.m128_f32[0];
              *(_DWORD *)distance = _mm_sqrt_ps(mNext_low).m128_u32[0];
              *(_DWORD *)distance_2d = _mm_sqrt_ps(mPrev_high).m128_u32[0];
              return 1;
            }
          }
        }
      }
    }
  }
  return v8;
}

// File Line: 4782
// RVA: 0x50B960
void __fastcall UFG::TSCharacter::Mthd_standing_adjust(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  int i_user_data; // ebx
  int v5; // ebx
  UFG::GameStatTracker *v6; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      v5 = (int)(float)(UFG::PlayerBuffTracker::GetFaceXPBonusPercent() * (float)i_user_data) + i_user_data;
      v6 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v6, Standing, v5);
    }
  }
}

// File Line: 4802
// RVA: 0x50BCC0
void __fastcall UFG::TSCharacter::Mthd_standing_set(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  SSInstance *i_data_p; // rbx
  UFG::GameStatTracker *v5; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
      v5 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v5, Standing, i_data_p->i_user_data);
    }
  }
}

// File Line: 4816
// RVA: 0x4F95A0
void __fastcall UFG::TSCharacter::Mthd_face_get_action(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  unsigned int v4; // r9d
  int m_NameUID; // r10d
  UFG::SimComponent *m_pComponent; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0;
  m_NameUID = 18;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        m_NameUID = m_pComponent[3].m_NameUID;
    }
  }
  if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumNameHash.p[m_NameUID];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *ppResult = SSSymbol::as_instance(v8);
}

// File Line: 4843
// RVA: 0x4F9770
void __fastcall UFG::TSCharacter::Mthd_face_set_action(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SceneObjectProperties *m_pSceneObj; // rdi
  UFG::FaceActionComponent *FaceActionComponent; // rbx
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // r14
  bool v9; // bp
  bool v10; // r12
  bool v11; // r13
  SSInstance *v12; // r15
  UFG::qPropertySet *WritableProperties; // rsi
  UFG::qPropertySet *PropertySet; // rax
  UFG::qSymbol sym; // [rsp+20h] [rbp-48h] BYREF
  bool v16; // [rsp+70h] [rbp+8h]
  bool v17; // [rsp+88h] [rbp+20h]

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pSceneObj = this->mpSimObj.m_pPointer->m_pSceneObj;
    if ( (m_pPointer->m_Flags & 0x4000) == 0
      || (FaceActionComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent) == 0i64 )
    {
      FaceActionComponent = UFG::FaceActionComponent::CreateFaceActionComponent(m_pSceneObj);
    }
    i_array_p = pScope->i_data.i_array_p;
    sym.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_data_p = i_array_p[1]->i_data_p;
    v9 = i_array_p[2]->i_data_p->i_user_data != 0;
    v10 = i_array_p[3]->i_data_p->i_user_data != 0;
    v11 = i_array_p[4]->i_data_p->i_user_data != 0;
    v12 = i_array_p[7]->i_data_p;
    v16 = i_array_p[5]->i_data_p->i_user_data != 0;
    v17 = i_array_p[6]->i_data_p->i_user_data != 0;
    UFG::FaceActionComponent::LookupFaceAction(&sym);
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
    if ( !UFG::qPropertySet::GetParentFromName(
            WritableProperties,
            (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentFaceAction,
            DEPTH_RECURSE) )
    {
      PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(&SimSymX_propset_componentFaceAction);
      UFG::PSWrapper::AppendParentLocal(WritableProperties, PropertySet);
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_FaceAction, &sym);
    PropertyUtils::SetRuntime<unsigned long>(
      m_pSceneObj,
      (UFG::qArray<unsigned long,0> *)&SimSym_PipsRequired,
      i_data_p->i_user_data);
    PropertyUtils::SetRuntime<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_Hidden, v9);
    PropertyUtils::SetRuntime<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_RemoveOnCompletion, v10);
    PropertyUtils::SetRuntime<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_FaceActionEnabled, v11);
    PropertyUtils::SetRuntime<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_MinigameSetup, v16);
    PropertyUtils::SetRuntime<bool>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_MinigameEnabled, v17);
    PropertyUtils::SetRuntime<unsigned long>(
      m_pSceneObj,
      (UFG::qArray<unsigned long,0> *)&SimSym_MinigameSpeed,
      v12->i_user_data);
    if ( FaceActionComponent )
      FaceActionComponent->vfptr[12].__vecDelDtor(FaceActionComponent, (unsigned int)m_pSceneObj);
  }
}

// File Line: 4907
// RVA: 0x4F99C0
void __fastcall UFG::TSCharacter::Mthd_face_set_purchase_item(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // r12
  UFG::SceneObjectProperties *m_pSceneObj; // r14
  UFG::qPropertySet *WritableProperties; // rbx
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v10; // rax
  UFG::qPropertyList *v11; // rsi
  unsigned int mNumElements; // ebp
  unsigned int v13; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v15; // rbx
  UFG::SimObject *v16; // rcx
  UFG::InventoryComponent *m_pComponent; // rcx
  UFG::qPropertySet *mpWritableProperties; // rdx
  UFG::SimObject *v19; // rcx
  UFG::FaceActionComponent *v20; // rbx
  UFG::qSymbol v; // [rsp+50h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    i_array_p = pScope->i_data.i_array_p;
    v.mUID = (*i_array_p)->i_data_p->i_user_data;
    i_data_p = i_array_p[1]->i_data_p;
    if ( (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    m_pSceneObj = m_pPointer->m_pSceneObj;
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
    if ( !UFG::qPropertySet::GetParentFromName(
            WritableProperties,
            (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentFaceAction,
            DEPTH_RECURSE) )
    {
      PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(&SimSymX_propset_componentFaceAction);
      UFG::PSWrapper::AppendParentLocal(WritableProperties, PropertySet);
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&SimSym_SellableItem, &v);
    v10 = UFG::SceneObjectProperties::GetWritableProperties(m_pSceneObj);
    v11 = PropertyUtils::Get<UFG::qPropertyList>(v10, (UFG::qArray<unsigned long,0> *)&UFG::gsymInventory, DEPTH_LOCAL);
    if ( !v11 )
    {
      v11 = UFG::qPropertyList::Create("inventory list");
      PropertyUtils::SetRuntime<UFG::qPropertyList>(
        m_pSceneObj,
        (UFG::qArray<unsigned long,0> *)&UFG::gsymInventory,
        v11);
    }
    mNumElements = v11->mNumElements;
    v13 = 0;
    if ( mNumElements )
    {
      while ( 1 )
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v11, 0x1Au, v13);
        if ( ValuePtr && *(_QWORD *)ValuePtr )
          v15 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
        else
          v15 = 0i64;
        if ( v15->mName.mUID == v.mUID )
          break;
        if ( ++v13 >= mNumElements )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v15 = UFG::qPropertySet::CreateContainedSet(&v, "item_set");
      UFG::qPropertyList::Add<UFG::qPropertySet>(v11, v15);
    }
    if ( UFG::qPropertySet::PropertyExists(v15, (UFG::qArray<unsigned long,0> *)&UFG::gsymRange, DEPTH_LOCAL) )
      UFG::qPropertySet::RemovePropertyByName(v15, (UFG::qArray<unsigned long,0> *)&UFG::gsymRange);
    UFG::qPropertySet::Set<long>(v15, (UFG::qArray<unsigned long,0> *)&UFG::gsymValue, i_data_p->i_user_data);
    v16 = this->mpSimObj.m_pPointer;
    if ( v16 )
    {
      if ( (v16->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InventoryComponent *)v16->m_Components.p[39].m_pComponent;
        if ( m_pComponent )
        {
          mpWritableProperties = m_pSceneObj->mpWritableProperties;
          if ( !mpWritableProperties )
            mpWritableProperties = m_pSceneObj->mpConstProperties;
          UFG::InventoryComponent::ResetFromProperties(m_pComponent, mpWritableProperties);
        }
      }
    }
    v19 = this->mpSimObj.m_pPointer;
    if ( v19 && (v19->m_Flags & 0x4000) != 0 )
    {
      v20 = (UFG::FaceActionComponent *)v19->m_Components.p[45].m_pComponent;
      if ( v20 )
      {
        v20->vfptr[12].__vecDelDtor(v20, (unsigned int)m_pSceneObj);
        UFG::FaceActionComponent::ProcessIconLogic(v20);
      }
    }
  }
}igned int)m_pSceneObj);
        UFG::FaceActionComponent::ProcessIconLogic(v20);
      }

// File Line: 4986
// RVA: 0x4F9650
void __fastcall UFG::TSCharacter::Mthd_face_get_action_min_requirement(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx
  unsigned int m_pSimObject; // edi
  UFG::GameStatTracker *v7; // rax
  unsigned int FaceLevel; // eax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    m_pSimObject = 0;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer == UFG::GetLocalPlayer() )
    {
      v7 = UFG::GameStatTracker::Instance();
      FaceLevel = UFG::GameStatTracker::GetFaceLevel(v7);
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, FaceLevel);
    }
    else
    {
      v9 = this->mpSimObj.m_pPointer;
      if ( v9 && (v9->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v9->m_Components.p[45].m_pComponent;
        if ( m_pComponent )
          m_pSimObject = (unsigned int)m_pComponent[3].m_pSimObject;
      }
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, m_pSimObject);
  }
}

// File Line: 5012
// RVA: 0x4F9500
void __fastcall UFG::TSCharacter::Mthd_face_action_auto_completes_objective(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // r8
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-30h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      UFG::qString::qString(&v6, *(const char **)i_data_p->i_user_data);
      UFG::qString::Set(
        (UFG::qString *)&m_pComponent[10].m_BoundComponentHandles.mNode.mNext,
        v6.mData,
        v6.mLength,
        0i64,
        0);
      UFG::qString::~qString(&v6);
    }
  }
}

// File Line: 5024
// RVA: 0x4F9730
void __fastcall UFG::TSCharacter::Mthd_face_meter_set(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      UFG::GameStatAction::Player::ClampAndSetCombatMeter((float)SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 5055
// RVA: 0x4E5E20
void __fastcall UFG::TSCharacter::MthdC_face_is_action_success(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // dl
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_SUCCESS;
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 5075
// RVA: 0x4E5AE0
void __fastcall UFG::TSCharacter::MthdC_face_has_been_greeted(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx
  char v5; // al

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && ((v5 = BYTE4(m_pComponent[12].m_pSimObject), (v5 & 1) != 0)
       || BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev))
      && (v5 & 2) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5095
// RVA: 0x4E6020
void __fastcall UFG::TSCharacter::MthdC_face_set_greeted(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // r8
  bool v5; // dl
  char v6; // al
  UFG::eFaceActionState v7; // edx
  char v8; // cl

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v5 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
        BYTE4(m_pComponent[12].m_pSimObject) &= ~2u;
        BYTE4(m_pComponent[12].m_pSimObject) |= 2 * v5;
        v6 = BYTE4(m_pComponent[12].m_pSimObject);
        if ( v5 )
        {
          v7 = eFACE_ACTION_STATE_COMPLETE;
          if ( (v6 & 4) != 0 )
            v7 = eFACE_ACTION_STATE_WAITING_FOR_CHARGE;
        }
        else
        {
          if ( (v6 & 1) != 0 || (v8 = 0, BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev)) )
            v8 = 1;
          v7 = eFACE_ACTION_STATE_WAITING_FOR_CHARGE;
          if ( v8 )
            v7 = eFACE_ACTION_STATE_WAITING_FOR_GREET;
        }
        UFG::FaceActionComponent::SetState((UFG::FaceActionComponent *)m_pComponent, v7);
      }
    }
  }
}

// File Line: 5111
// RVA: 0x4E60E0
void __fastcall UFG::TSCharacter::MthdC_face_set_requires_greet(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      BYTE4(m_pComponent[12].m_pSimObject) ^= (BYTE4(m_pComponent[12].m_pSimObject) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
  }
}

// File Line: 5123
// RVA: 0x4E5FB0
void __fastcall UFG::TSCharacter::MthdC_face_set_auto_charge(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      BYTE4(m_pComponent[3].m_SafePointerList.mNode.mPrev) ^= (BYTE4(m_pComponent[3].m_SafePointerList.mNode.mPrev) ^ (8 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 8;
  }
}

// File Line: 5139
// RVA: 0x4E59F0
void __fastcall UFG::TSCharacter::MthdC_face_get_success_state(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::eSocialInteractionResultEnum FaceActionSuccessState; // edx
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    FaceActionSuccessState = eSOCIALINTERACTIONRESULT_INVALID;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        FaceActionSuccessState = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)FaceActionSuccessState);
  }
}

// File Line: 5159
// RVA: 0x4E5A60
void __fastcall UFG::TSCharacter::MthdC_face_get_success_state_as_symbol(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::eSocialInteractionResultEnum FaceActionSuccessState; // edx
  UFG::FaceActionComponent *m_pComponent; // rcx
  ASymbol *v7; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    FaceActionSuccessState = eSOCIALINTERACTIONRESULT_INVALID;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        FaceActionSuccessState = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent);
    }
    v7 = (ASymbol *)UFG::qSymbol::create_from_string(&result, UFG::SocialInteractionResultNames[FaceActionSuccessState]);
    *ppResult = SSSymbol::as_instance(v7);
  }
}

// File Line: 5180
// RVA: 0x4F10D0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_last_conversation_result(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  int m_pSimObject; // edx
  UFG::SimComponent *m_pComponent; // rcx
  ASymbol *v7; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    m_pSimObject = 0;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        m_pSimObject = (int)m_pComponent[10].m_pSimObject;
    }
    v7 = (ASymbol *)UFG::qSymbol::create_from_string(&result, UFG::SocialInteractionResultNames[m_pSimObject]);
    *ppResult = SSSymbol::as_instance(v7);
  }
}

// File Line: 5200
// RVA: 0x4E5B70
void __fastcall UFG::TSCharacter::MthdC_face_is_action_failure(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v5; // dl
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 1;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        v5 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_FAILURE;
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 5220
// RVA: 0x4E5D40
void __fastcall UFG::TSCharacter::MthdC_face_is_action_minigame_success(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v4; // dl
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v4 = 0;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_MINIGAMESUCCESS;
    }
    *ppResult = SSBoolean::pool_new(v4);
  }
}

// File Line: 5240
// RVA: 0x4E5CD0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_minigame_failure(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  bool v5; // dl
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    v5 = 1;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        v5 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_MINIGAMEFAILURE;
    }
    *ppResult = SSBoolean::pool_new(v5);
  }
}

// File Line: 5260
// RVA: 0x4E5C50
void __fastcall UFG::TSCharacter::MthdC_face_is_action_greet_success(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && (BYTE4(m_pComponent[12].m_pSimObject) & 2) != 0 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5277
// RVA: 0x4E5BE0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_greet_failure(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rcx
  bool v6; // al

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = 0i64;
    v6 = 1;
    if ( m_pComponent )
      v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_GREETFAILURE;
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 5298
// RVA: 0x4E5DB0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_other_failure(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rcx
  bool v6; // al

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    else
      m_pComponent = 0i64;
    v6 = 1;
    if ( m_pComponent )
      v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) == eSOCIALINTERACTIONRESULT_OTHERFAILURE;
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 5319
// RVA: 0x4E56E0
void __fastcall UFG::TSCharacter::MthdC_face_action_enable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::FaceActionComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      UFG::FaceActionComponent::FaceActionEnable(m_pComponent, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 5333
// RVA: 0x4E6150
void __fastcall UFG::TSCharacter::MthdC_face_toggle_social_icon(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::FaceActionComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      UFG::FaceActionComponent::ToggleGreetIcon(m_pComponent, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 5348
// RVA: 0x4EAFA0
void __fastcall UFG::TSCharacter::MthdC_minigame_setup(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 5362
// RVA: 0x4E5740
void __fastcall UFG::TSCharacter::MthdC_face_action_is_enabled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && UFG::FaceActionComponent::IsFaceActionEnabled(m_pComponent) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5377
// RVA: 0x4E58C0
void __fastcall UFG::TSCharacter::MthdC_face_action_is_setup(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer
      && (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && m_pComponent[3].m_NameUID != 18 )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5408
// RVA: 0x4E57C0
void __fastcall UFG::TSCharacter::MthdC_face_action_is_minigame_enabled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && BYTE5(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5424
// RVA: 0x4E5840
void __fastcall UFG::TSCharacter::MthdC_face_action_is_minigame_setup(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = this->mpSimObj.m_pPointer;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (m_pComponent = m_pPointer->m_Components.p[45].m_pComponent) != 0i64
      && BYTE4(m_pComponent[3].m_BoundComponentHandles.mNode.mPrev) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5437
// RVA: 0x4E5930
void __fastcall UFG::TSCharacter::MthdC_face_get_level(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // rbx
  UFG::GameStatTracker *v6; // rax
  unsigned __int64 FaceLevel; // rdx
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *m_pComponent; // rcx

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    if ( m_pPointer == UFG::GetLocalPlayer() )
    {
      v6 = UFG::GameStatTracker::Instance();
      FaceLevel = (unsigned int)UFG::GameStatTracker::GetFaceLevel(v6);
LABEL_11:
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, FaceLevel);
      return;
    }
    v8 = this->mpSimObj.m_pPointer;
    if ( v8 )
    {
      if ( (v8->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v8->m_Components.p[45].m_pComponent;
        if ( m_pComponent )
        {
          FaceLevel = LODWORD(m_pComponent[3].m_pSimObject);
          goto LABEL_11;
        }
      }
    }
  }
}

// File Line: 5461
// RVA: 0x4E5E90
void __fastcall UFG::TSCharacter::MthdC_face_meter_enable(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceMeterComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      LOBYTE(ComponentOfTypeHK[135].m_SafePointerList.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 5472
// RVA: 0x4E5F00
void __fastcall UFG::TSCharacter::MthdC_face_meter_is_enabled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceMeterComponent::_TypeUID);
        if ( ComponentOfTypeHK )
          *ppResult = SSBoolean::pool_new((bool)ComponentOfTypeHK[135].m_SafePointerList.mNode.mPrev);
      }
    }
  }
}

// File Line: 5565
// RVA: 0x4F12F0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_is_playing(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v3; // di
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::Conversation *ConversationReference; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        ConversationReference = UFG::FaceActionComponent::GetConversationReference(m_pComponent, v7);
        if ( ConversationReference )
          v3 = ConversationReference->m_state == eConversationState_Playing;
      }
    }
  }
  *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 5585
// RVA: 0x4F1420
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_play(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::PlayConversation(m_pComponent, v5);
    }
  }
}

// File Line: 5596
// RVA: 0x4F17B0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_stop(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::StopConversation(m_pComponent, v5);
    }
  }
}

// File Line: 5607
// RVA: 0x4F1CD0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_play(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::PlayPostInteractionConversation(m_pComponent, v5);
    }
  }
}

// File Line: 5618
// RVA: 0x4F1DE0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_stop(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::StopPostInteractionConversation(m_pComponent, v5);
    }
  }
}

// File Line: 5639
// RVA: 0x4F1830
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_stop_all_conversations(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      UFG::FaceActionComponent::StopAllConversations(m_pComponent);
  }
}

// File Line: 5644
// RVA: 0x4F1950
void __fastcall UFG::TSCharacter::MthdC_social_interaction_set_should_exit(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::SimObject *m_pPointer; // rdx
  bool v5; // di
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  sym.mUID = (*i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetShouldInteractionExit(m_pComponent, v7, v5);
    }
  }
}

// File Line: 5656
// RVA: 0x4F19E0
void __fastcall UFG::TSCharacter::MthdC_social_interaction_should_exit(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::FaceActionComponent *m_pComponent; // rbx
  bool ShouldInteractionExit; // al
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = 0i64;
  ShouldInteractionExit = 0;
  if ( m_pComponent )
  {
    v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
    ShouldInteractionExit = UFG::FaceActionComponent::ShouldInteractionExit(m_pComponent, v7);
  }
  *ppResult = SSBoolean::pool_new(ShouldInteractionExit);
}

// File Line: 5669
// RVA: 0x4F1690
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_should_reset(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::SimObject *m_pPointer; // rdx
  bool v5; // di
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  sym.mUID = (*i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetShouldConversationReset(m_pComponent, v7, v5);
    }
  }
}

// File Line: 5681
// RVA: 0x4F1720
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_should_reset(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::FaceActionComponent *m_pComponent; // rbx
  bool ShouldConversationReset; // al
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = 0i64;
  ShouldConversationReset = 0;
  if ( m_pComponent )
  {
    v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
    ShouldConversationReset = UFG::FaceActionComponent::ShouldConversationReset(m_pComponent, v7);
  }
  *ppResult = SSBoolean::pool_new(ShouldConversationReset);
}

// File Line: 5694
// RVA: 0x4F1260
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_has_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v3; // r9
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        v3 = UFG::FaceActionComponent::GetConversationReference(m_pComponent, v7) != 0i64;
      }
    }
  }
  *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 5709
// RVA: 0x4F11C0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v6; // eax
  UFG::Conversation *ConversationReference; // rax
  SSInstance *vfptr; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v6 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        ConversationReference = UFG::FaceActionComponent::GetConversationReference(m_pComponent, v6);
        if ( ConversationReference )
        {
          if ( ConversationReference->m_type == eConversationType_Scripted )
          {
            vfptr = (SSInstance *)ConversationReference[1].vfptr;
            if ( vfptr )
              ++vfptr->i_ref_count;
            *ppResult = vfptr;
          }
        }
      }
    }
  }
}

// File Line: 5729
// RVA: 0x4F15E0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // rdi
  unsigned int i_class_p; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v10; // eax
  UFG::qSymbol sym; // [rsp+38h] [rbp+10h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  sym.mUID = (*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  i_class_p = (unsigned int)i_data_p[1].i_class_p;
  if ( i_class_p )
  {
    v7 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, i_class_p);
    if ( v7 )
    {
      if ( v7 != (UFG::qBaseTreeRB *)8 )
      {
        m_pPointer = this->mpSimObj.m_pPointer;
        if ( m_pPointer )
        {
          if ( (m_pPointer->m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
            if ( m_pComponent )
            {
              v10 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
              UFG::FaceActionComponent::SetConversationReference(
                m_pComponent,
                v10,
                (UFG::Conversation *)i_data_p[2].i_user_data);
            }
          }
        }
      }
    }
  }
}

// File Line: 5746
// RVA: 0x4E5690
void __fastcall UFG::TSCharacter::MthdC_face_action_clear(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      UFG::FaceActionComponent::ClearConversationReferences(m_pComponent);
  }
}

// File Line: 5756
// RVA: 0x4F1BB0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_has_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v3; // r9
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        v3 = UFG::FaceActionComponent::GetPostInteractionConversationReference(m_pComponent, v7) != 0i64;
      }
    }
  }
  *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 5771
// RVA: 0x4F1B10
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_get_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v6; // eax
  UFG::Conversation *PostInteractionConversationReference; // rax
  SSInstance *vfptr; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v6 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        PostInteractionConversationReference = UFG::FaceActionComponent::GetPostInteractionConversationReference(
                                                 m_pComponent,
                                                 v6);
        if ( PostInteractionConversationReference )
        {
          if ( PostInteractionConversationReference->m_type == eConversationType_Scripted )
          {
            vfptr = (SSInstance *)PostInteractionConversationReference[1].vfptr;
            if ( vfptr )
              ++vfptr->i_ref_count;
            *ppResult = vfptr;
          }
        }
      }
    }
  }
}

// File Line: 5791
// RVA: 0x4F1D50
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_set_reference(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  UFG::SimObject *m_pPointer; // rdx
  SSInstance *i_data_p; // rdi
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  sym.mUID = (*i_array_p)->i_data_p->i_user_data;
  i_data_p = i_array_p[1]->i_data_p;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetPostInteractionConversationReference(
        m_pComponent,
        v7,
        (UFG::Conversation *)i_data_p[2].i_user_data);
    }
  }
}

// File Line: 5804
// RVA: 0x4F1390
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_is_valid(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool v3; // r9
  UFG::SimObject *m_pPointer; // rdx
  hkGeometryUtils::IVertices *m_pComponent; // rbx
  int v7; // eax
  int v8; // r8d
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (hkGeometryUtils::IVertices *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        v3 = Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(m_pComponent, v7, v8);
      }
    }
  }
  *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 5818
// RVA: 0x4F1C40
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_is_valid(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  bool IsPostInteractionConversationValid; // r9
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  IsPostInteractionConversationValid = 0;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
        IsPostInteractionConversationValid = UFG::FaceActionComponent::IsPostInteractionConversationValid(
                                               m_pComponent,
                                               v7);
      }
    }
  }
  *ppResult = SSBoolean::pool_new(IsPostInteractionConversationValid);
}

// File Line: 5832
// RVA: 0x4F1150
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_last_played(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rcx
  UFG::Conversation *LastPlayedConversation; // rax
  SSInstance *vfptr; // rax

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
      {
        LastPlayedConversation = UFG::FaceActionComponent::GetLastPlayedConversation(m_pComponent);
        if ( LastPlayedConversation )
        {
          if ( LastPlayedConversation->m_type == eConversationType_Scripted )
          {
            vfptr = (SSInstance *)LastPlayedConversation[1].vfptr;
            if ( vfptr )
              ++vfptr->i_ref_count;
            *ppResult = vfptr;
          }
        }
      }
    }
  }
}

// File Line: 5852
// RVA: 0x4F1590
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_last_played(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      LODWORD(m_pComponent[10].m_pSimObject) = 0;
  }
}

// File Line: 5865
// RVA: 0x4F1880
void __fastcall UFG::TSCharacter::MthdC_social_interaction_has_occurred(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rcx
  bool v6; // al

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = 0i64;
  v6 = 0;
  if ( m_pComponent )
    v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) != eSOCIALINTERACTIONRESULT_INVALID;
  *ppResult = SSBoolean::pool_new(v6);
}

// File Line: 5877
// RVA: 0x4F1A70
void __fastcall UFG::TSCharacter::MthdC_social_minigame_finished_playing(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rbx
  UFG::FaceActionComponent *m_pComponent; // rbx
  bool v6; // cl

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = 0i64;
  v6 = 0;
  if ( m_pComponent )
  {
    if ( UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) != eSOCIALINTERACTIONRESULT_MINIGAMESUCCESS
      && UFG::FaceActionComponent::GetFaceActionSuccessState(m_pComponent) != eSOCIALINTERACTIONRESULT_MINIGAMEFAILURE )
    {
      *ppResult = SSBoolean::pool_new(0);
      return;
    }
    v6 = 1;
  }
  *ppResult = SSBoolean::pool_new(v6);
}

// File Line: 5889
// RVA: 0x4F18F0
void __fastcall UFG::TSCharacter::MthdC_social_interaction_has_succeeded(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::FaceActionComponent *m_pComponent; // rcx
  bool HasInteractionSucceeded; // al

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
  else
    m_pComponent = 0i64;
  HasInteractionSucceeded = 0;
  if ( m_pComponent )
    HasInteractionSucceeded = UFG::FaceActionComponent::HasInteractionSucceeded(m_pComponent);
  *ppResult = SSBoolean::pool_new(HasInteractionSucceeded);
}

// File Line: 5901
// RVA: 0x4F1520
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_face_action(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
      HIDWORD(m_pComponent[10].m_pSimObject) = UFG::FaceActionComponent::LookupFaceAction(&sym);
  }
}

// File Line: 5912
// RVA: 0x4F1040
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_face_action(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  unsigned int v4; // r9d
  int m_pSimObject_high; // r10d
  UFG::SimComponent *m_pComponent; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0;
  m_pSimObject_high = 0;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        m_pSimObject_high = HIDWORD(m_pComponent[10].m_pSimObject);
    }
  }
  if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumNameHash.p[m_pSimObject_high];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *ppResult = SSSymbol::as_instance(v8);
}

// File Line: 5928
// RVA: 0x4F14A0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_conversation_state(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::FaceActionComponent *m_pComponent; // rbx
  UFG::eSocialConversationStateEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h] BYREF

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
    if ( m_pComponent )
    {
      v5 = UFG::FaceActionComponent::LookupConversationState(&sym);
      UFG::FaceActionComponent::SetConversationState(m_pComponent, v5);
    }
  }
}

// File Line: 5939
// RVA: 0x4F0FC0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_conversation_state(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  unsigned int v4; // ebx
  UFG::eSocialConversationStateEnum ConversationState; // r9d
  UFG::FaceActionComponent *m_pComponent; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0;
  ConversationState = eSOCIAL_CONVERSATION_STATE_INVALID;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::FaceActionComponent *)m_pPointer->m_Components.p[45].m_pComponent;
      if ( m_pComponent )
        ConversationState = UFG::FaceActionComponent::GetConversationState(m_pComponent);
    }
  }
  if ( (UFG::gConversationStateEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gConversationStateEnum.m_enumLists.p)->m_enumNameHash.p[ConversationState];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *ppResult = SSSymbol::as_instance(v8);
}

// File Line: 5956
// RVA: 0x4F0F90
void __fastcall UFG::TSCharacter::MthdC_social_combat_fast_talk_get_succeeded(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  *ppResult = SSBoolean::pool_new((BYTE2(this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) & 2) != 0);
}

// File Line: 5961
// RVA: 0x506F80
void __fastcall UFG::TSCharacter::Mthd_set_animation_lod_enabled(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rbx
  UFG::AnimationLODComponent *v6; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      p = m_pPointer->m_Components.p;
      m_pComponent = p[13].m_pComponent;
      if ( m_pComponent )
      {
        v6 = (UFG::AnimationLODComponent *)p[13].m_pComponent;
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        {
          ((void (__fastcall *)(UFG::AnimationLODComponent *))m_pComponent->vfptr[9].__vecDelDtor)(v6);
        }
        else
        {
          UFG::AnimationLODComponent::MakeHighLOD(v6);
          ((void (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[8].__vecDelDtor)(m_pComponent);
        }
      }
    }
  }
}

// File Line: 5996
// RVA: 0x4E8D00
void __fastcall UFG::TSCharacter::MthdC_grant_player_buff(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData *v3; // rcx
  UFG::ePlayerBuffEnum v4; // edx
  SSInstance *i_data_p; // rax
  UFG::qStaticSymbol *v6; // rcx
  int i_user_data; // eax

  v3 = *pScope->i_data.i_array_p;
  v4 = ePLAYER_BUFF_NONE;
  i_data_p = v3->i_data_p;
  v6 = UFG::PlayerBuffEnumSymbols;
  i_user_data = i_data_p->i_user_data;
  while ( i_user_data != v6->mUID )
  {
    ++v6;
    ++v4;
    if ( (__int64)v6 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_PISTOL_SERVICE_AMMO )
    {
      UFG::PlayerBuffTracker::ActivateBuff(ePLAYER_BUFF_NONE);
      return;
    }
  }
  UFG::PlayerBuffTracker::ActivateBuff(v4);
}

// File Line: 6006
// RVA: 0x4E9760
void __fastcall UFG::TSCharacter::MthdC_is_player_buff_active(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ePlayerBuffEnum v3; // r9d
  SSData *v5; // rcx
  UFG::ePlayerBuffEnum v6; // edx
  SSInstance *i_data_p; // rax
  UFG::qStaticSymbol *v8; // rcx
  int i_user_data; // eax
  bool IsBuffActive; // al

  v3 = ePLAYER_BUFF_NONE;
  v5 = *pScope->i_data.i_array_p;
  v6 = ePLAYER_BUFF_NONE;
  i_data_p = v5->i_data_p;
  v8 = UFG::PlayerBuffEnumSymbols;
  i_user_data = i_data_p->i_user_data;
  while ( i_user_data != v8->mUID )
  {
    ++v8;
    ++v6;
    if ( (__int64)v8 >= (__int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_PISTOL_SERVICE_AMMO )
      goto LABEL_6;
  }
  v3 = v6;
LABEL_6:
  IsBuffActive = UFG::PlayerBuffTracker::IsBuffActive(v3);
  *ppResult = SSBoolean::pool_new(IsBuffActive);
}

// File Line: 6021
// RVA: 0x511A40
char __fastcall UFG::TSCharacter::get_attack_param_real(
        UFG::qPropertySet *propSet,
        UFG::qSymbol *propName,
        float *value)
{
  int v5; // xmm6_4
  UFG::qPropertySet *v6; // rax
  char *MemImagePtr; // rax
  unsigned int mUID; // ecx

  v5 = 0;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         propSet,
         (UFG::qArray<unsigned long,0> *)&object_physical_character_stats_BaseAttackParameters::sPropertyName,
         DEPTH_RECURSE);
  if ( !v6 )
    goto LABEL_5;
  MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v6);
  if ( !MemImagePtr )
    goto LABEL_5;
  mUID = propName->mUID;
  if ( propName->mUID == gsymMaxDistanceToChooseCloseAttack.mUID )
  {
    v5 = *(_DWORD *)MemImagePtr;
LABEL_5:
    *(_DWORD *)value = v5;
    return 1;
  }
  if ( mUID == gsymExitDistanceForCloseAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 1);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxDistanceToChooseMidAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 2);
    goto LABEL_5;
  }
  if ( mUID == gsymExitDistanceForMidAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 3);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxDistanceToUseCloseAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 4);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxDistanceToUseMidAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 5);
    goto LABEL_5;
  }
  if ( mUID == gsymMinRunningAttackDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 7);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxRunningAttackDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 8);
    goto LABEL_5;
  }
  if ( mUID == gsymRunningAttackExitDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 9);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunisticMeleeAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 10);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunisticMeleeAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 11);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunisticMeleeExitDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 12);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityMeleeAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 13);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityMeleeAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 14);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityMeleeExitDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 15);
    goto LABEL_5;
  }
  if ( mUID == gsymMinTimeBeforeOpportunityMeleeAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 16);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxTimeBeforeOpportunityMeleeAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 17);
    goto LABEL_5;
  }
  if ( mUID == gsymMinForOpportunityMeleeAttackTimeout.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 18);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxForOpportunityMeleeAttackTimeout.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 19);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityRangedAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 20);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityRangedAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 21);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxOpportunityRangedExitDistance.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 22);
    goto LABEL_5;
  }
  if ( mUID == gsymMinTimeBeforeOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 23);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxTimeBeforeOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 24);
    goto LABEL_5;
  }
  if ( mUID == gsymMinTimeBeforeNextOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 25);
    goto LABEL_5;
  }
  if ( mUID == gsymMaxTimeBeforeNextOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 26);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 27);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 28);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 29);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 30);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeVSHumanAsEnemyMobBattle.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 31);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeVSHumanAsEnemyMobBattle.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 32);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 33);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 34);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 35);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 36);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 37);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 38);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 39);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 40);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 41);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 42);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 43);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 44);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 45);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 46);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 47);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 48);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 49);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 50);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 51);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 52);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 53);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 54);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 55);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 56);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 57);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 58);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 59);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 60);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 61);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 62);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 63);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 64);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 65);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 66);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 67);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 68);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 69);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 70);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 71);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 72);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 73);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 74);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 75);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 76);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 77);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 78);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 79);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 80);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinMeleeDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 81);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxMeleeDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 82);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 83);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 84);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 85);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 86);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 87);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 88);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 89);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 90);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 91);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 92);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinRangedInCoverDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 93);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxRangedInCoverDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 94);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMinDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 95);
    goto LABEL_5;
  }
  if ( mUID == gsymInitialAttackTimeMaxDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 96);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 97);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 98);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMinDirectFollowersDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 99);
    goto LABEL_5;
  }
  if ( mUID == gsymAttackTimeMaxDirectFollowersDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)MemImagePtr + 100);
    goto LABEL_5;
  }
  return 0;
}

// File Line: 6142
// RVA: 0x4FB840
void __fastcall UFG::TSCharacter::Mthd_get_attack_param_real(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData *v4; // rdx
  UFG::SimObject *m_pPointer; // rax
  UFG::qSymbol *i_data_p; // r9
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  float value; // [rsp+30h] [rbp+8h] BYREF

  v4 = *pScope->i_data.i_array_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  value = 0.0;
  i_data_p = (UFG::qSymbol *)v4->i_data_p;
  m_pSceneObj = m_pPointer->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  UFG::TSCharacter::get_attack_param_real(mpWritableProperties, i_data_p + 8, &value);
  *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(value));
}

// File Line: 6155
// RVA: 0x4FB7B0
void __fastcall UFG::TSCharacter::Mthd_get_attack_param_int(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned int ChanceToUseMidAttack; // ebx
  SSInstance *i_data_p; // rdi
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v8; // rax
  object_physical_character_stats_BaseAttackParameters *MemImagePtr; // rax

  ChanceToUseMidAttack = 0;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  m_pSceneObj = this->mpSimObj.m_pPointer->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&object_physical_character_stats_BaseAttackParameters::sPropertyName,
         DEPTH_RECURSE);
  if ( v8 )
  {
    MemImagePtr = (object_physical_character_stats_BaseAttackParameters *)UFG::qPropertySet::GetMemImagePtr(v8);
    if ( MemImagePtr )
    {
      if ( LODWORD(i_data_p->i_user_data) == gsymChanceToUseMidAttack.mUID )
        ChanceToUseMidAttack = MemImagePtr->ChanceToUseMidAttack;
    }
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, ChanceToUseMidAttack);
}

// File Line: 6178
// RVA: 0x504DE0
void __fastcall UFG::TSCharacter::Mthd_money_adjust(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatAction::Money::Exchange(
    0i64,
    *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64),
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 6187
// RVA: 0x504E10
void __fastcall UFG::TSCharacter::Mthd_money_get(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatTracker *v4; // rax
  unsigned int Stat; // eax

  if ( ppResult )
  {
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, Money);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, Stat);
  }
}

// File Line: 6196
// RVA: 0x504E50
void __fastcall UFG::TSCharacter::Mthd_money_set(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::GameStatTracker *v4; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, Money, i_data_p->i_user_data);
}

// File Line: 6203
// RVA: 0x4FCC50
void __fastcall UFG::TSCharacter::Mthd_get_faction(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatTracker *v5; // rax
  UFG::SimObjectCVBase *m_pPointer; // rdx
  UFG::FactionInterface *p_mFactionInterface; // rsi
  UFG::eFactionClassEnum Faction; // eax
  UFG::qStaticSymbol *v9; // rax

  if ( ppResult )
  {
    v5 = UFG::FactionInterface::Get();
    m_pPointer = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    p_mFactionInterface = &v5->mFactionInterface;
    if ( !m_pPointer || (m_pPointer->m_Flags & 0x4000) == 0 )
      m_pPointer = 0i64;
    Faction = (unsigned int)UFG::FactionInterface::GetFaction(&v5->mFactionInterface, m_pPointer);
    v9 = UFG::FactionInterface::MapFactionToSymbol(p_mFactionInterface, Faction);
    *ppResult = SSSymbol::as_instance((ASymbol *)v9);
  }
}

// File Line: 6214
// RVA: 0x507F80
void __fastcall UFG::TSCharacter::Mthd_set_faction(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  SSInstance *i_data_p; // rbx
  UFG::GameStatTracker *v6; // rax
  UFG::SimObjectCVBase *v7; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    v6 = UFG::FactionInterface::Get();
    v7 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    if ( !v7 || (v7->m_Flags & 0x4000) == 0 )
      v7 = 0i64;
    UFG::FactionInterface::SetFaction(&v6->mFactionInterface, v7, (UFG::qSymbol *)&i_data_p->i_user_data);
  }
}

// File Line: 6231
// RVA: 0x4F41E0
void __fastcall UFG::TSCharacter::Mthd_add_follower(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *v7; // rcx
  UFG::ActiveAIEntityComponent *ComponentOfType; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          *i_array_p,
          ppResult) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  if ( this->mAIScriptInterfaceComponent.m_pSimComponent && i_data_p )
  {
    v7 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
    if ( v7 )
    {
      ComponentOfType = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                          v7,
                                                          UFG::ActiveAIEntityComponent::_TypeUID);
      UFG::AIScriptInterfaceComponent::AddFollower(
        (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent,
        ComponentOfType);
    }
  }
}

// File Line: 6245
// RVA: 0x4F93B0
void __fastcall UFG::TSCharacter::Mthd_equip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // rdi
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObject *v8; // rdx

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (SSActor *)(*i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          *i_array_p,
          ppResult) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      if ( i_data_p )
      {
        v8 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count;
        if ( v8 )
        {
          if ( (m_pPointer->m_Flags & 0x4000) == 0 )
            m_pPointer = 0i64;
          UFG::InventoryComponent::Equip(m_pPointer, v8);
        }
      }
    }
  }
}

// File Line: 6260
// RVA: 0x1541810
__int64 UFG::_dynamic_initializer_for__symGripRHand__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Grip R Hand", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symGripRHand, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symGripRHand__);
}

// File Line: 6264
// RVA: 0x50DE60
void __fastcall UFG::TSCharacter::Mthd_unequip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  SSData **i_array_p; // rdx
  bool v6; // r9
  char v7; // dl
  UFG::TargetingSystemBaseComponent *m_pComponent; // r13
  __int64 v9; // r15
  __int64 v10; // r12
  __int64 v11; // rcx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::SimObjectProp *v13; // rbx
  bool v14; // al
  __int16 m_Flags; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfTypeHK; // rax
  UFG::CharacterAnimationComponent *v17; // rdi
  UFG::SimObjectCharacter *SimObjectCharacter; // rax
  UFG::SimComponent *ComponentOfType; // rax
  Creature *mCreature; // rsi
  __int64 v21; // rdi
  int v22; // ebp
  int v23; // eax
  UFG::InventoryComponent *v24; // rcx
  UFG::SimObjectCharacter *v25; // rax
  __int64 v26; // r9
  UFG::CompositeDrawableComponent *v27; // rcx
  bool v28; // zf
  bool v29; // [rsp+40h] [rbp-78h]
  __int64 v30; // [rsp+48h] [rbp-70h]
  UFG::eTargetTypeEnum eTargetType[6]; // [rsp+58h] [rbp-60h]
  char v32; // [rsp+C0h] [rbp+8h]
  bool v33; // [rsp+D8h] [rbp+20h]

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      i_array_p = pScope->i_data.i_array_p;
      v29 = (*i_array_p)->i_data_p->i_user_data != 0;
      v6 = i_array_p[1]->i_data_p->i_user_data != 0;
      v33 = v6;
      v7 = 0;
      v32 = 0;
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
        if ( m_pComponent )
        {
          eTargetType[0] = eTARGET_TYPE_STOWED_WEAPON;
          eTargetType[1] = eTARGET_TYPE_EQUIPPED;
          eTargetType[2] = eTARGET_TYPE_STOWED_2H_WEAPON;
          if ( (_S10_9 & 1) == 0 )
          {
            _S10_9 |= 1u;
            UFG::qSymbolUC::create_from_string(BoneName, "Bip01 R Thigh");
            UFG::qSymbolUC::create_from_string(&stru_14240D774, "Bip01 R Prop");
            UFG::qSymbolUC::create_from_string(&stru_14240D778, "Bip01 L Thigh");
            atexit(UFG::TSCharacter::Mthd_unequip_::_8_::_dynamic_atexit_destructor_for__BoneName__);
            v7 = 0;
            v6 = v33;
          }
          v9 = 0i64;
          v30 = 3i64;
          do
          {
            v10 = (unsigned int)eTargetType[v9];
            v11 = (unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v10];
            m_pTargets = m_pComponent->m_pTargets;
            v13 = (UFG::SimObjectProp *)m_pTargets[v11].m_pTarget.m_pPointer;
            v14 = v13 && m_pTargets[v11].m_bLock;
            if ( !v13 || !v14 )
              goto LABEL_57;
            if ( !v6 || v7 )
            {
LABEL_27:
              if ( UFG::TSCharacter::GetSimObjectCharacter(this) )
              {
                SimObjectCharacter = UFG::TSCharacter::GetSimObjectCharacter(this);
                v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(SimObjectCharacter);
              }
              else
              {
                v17 = 0i64;
              }
              ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::CharacterAnimationComponent::_TypeUID);
              if ( v17 )
                mCreature = v17->mCreature;
              else
                mCreature = 0i64;
              if ( ComponentOfType )
                v21 = *(_QWORD *)&ComponentOfType[2].m_TypeUID;
              else
                v21 = 0i64;
              if ( mCreature && v21 )
              {
                v22 = mCreature->mPose.mRigHandle.mData
                    ? Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, BoneName[v9].mUID)
                    : -1;
                v23 = *(_QWORD *)(v21 + 440)
                    ? Skeleton::GetBoneID(*(Skeleton **)(v21 + 480), UFG::symGripRHand.mUID)
                    : -1;
                if ( v22 >= 0 && v23 >= 0 )
                {
                  if ( UFG::TSCharacter::GetSimObjectCharacter(this) )
                  {
                    v24 = (UFG::InventoryComponent *)UFG::TSCharacter::GetSimObjectCharacter(this)->m_Components.p[39].m_pComponent;
                    if ( v24 )
                    {
                      UFG::InventoryComponent::RemoveObjectFromInventory(v24, v13, v9 * 4);
                      v25 = UFG::TSCharacter::GetSimObjectCharacter(this);
                      Creature::RemoveAttachment(mCreature, v25, v22, v13);
                      LOBYTE(v26) = 1;
                      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
                        m_pComponent,
                        (unsigned int)v10,
                        0i64,
                        v26,
                        0,
                        "TSCharacter::Mthd_unequip",
                        0i64,
                        0i64);
                      UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, (UFG::eTargetTypeEnum)v10);
                      if ( UFG::TSCharacter::GetSimObjectCharacter(this) )
                      {
                        v27 = (UFG::CompositeDrawableComponent *)UFG::TSCharacter::GetSimObjectCharacter(this)->m_Components.p[14].m_pComponent;
                        if ( v27 )
                          UFG::CompositeDrawableComponent::SetIsHidden(v27, 0);
                      }
                      if ( this->mpSimObj.m_pPointer == LocalPlayer && (_DWORD)v10 == 17 )
                        UFG::GameStatAction::Inventory::UnEquip(0);
                      if ( v29 )
                        UFG::Simulation::DestroySimObject(&UFG::gSim, v13);
                    }
                  }
                }
              }
              v7 = v32;
              goto LABEL_57;
            }
            m_Flags = v13->m_Flags;
            if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
              goto LABEL_22;
            if ( (m_Flags & 0x2000) != 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v13);
              goto LABEL_24;
            }
            if ( (m_Flags & 0x1000) != 0 )
LABEL_22:
              ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               v13,
                                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            else
              ComponentOfTypeHK = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                               v13,
                                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_24:
            if ( !ComponentOfTypeHK
              || !ComponentOfTypeHK->mWeaponTypeInfo->mFireModes[ComponentOfTypeHK->mFireMode]->mStowable )
            {
              goto LABEL_27;
            }
            v7 = 1;
            v32 = 1;
LABEL_57:
            ++v9;
            v28 = v30-- == 1;
            v6 = v33;
          }
          while ( !v28 );
        }
      }
    }
  }
}

// File Line: 6382
// RVA: 0x50C3C0
void __fastcall UFG::TSCharacter::Mthd_stow_equipped_firearm(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rdx
  UFG::InventoryComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::InventoryComponent *)m_pPointer->m_Components.p[39].m_pComponent;
    if ( m_pComponent )
      UFG::InventoryComponent::Stow(m_pComponent, eINVENTORY_EQUIP_SLOT_RIGHT_HAND, eINVENTORY_EQUIP_SLOT_STOWED_1H);
  }
}

// File Line: 6401
// RVA: 0x4F4460
void __fastcall UFG::TSCharacter::Mthd_add_to_inventory(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  __int64 v3; // r15
  SSData **i_array_p; // r8
  int i_user_data; // edi
  UFG::SimObject *m_pPointer; // rax
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::SimObject *v10; // rcx
  UFG::InventoryComponent *m_pComponent; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 && (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v8 = UFG::qSymbol::create_from_string(&result, *(const char **)(*i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = &pTrackEnumBinding;
    pTrackEnumBinding.mNext = &pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol.mUID = -1;
    pTrackEnumBinding.m_EnumSymbol = (UFG::qSymbol)v8->mUID;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
    }
    else
    {
      mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
      pTrackEnumBinding.mPrev = mPrev;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue )
    {
      v10 = this->mpSimObj.m_pPointer;
      if ( v10 )
      {
        if ( (v10->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::InventoryComponent *)v10->m_Components.p[39].m_pComponent;
          if ( m_pComponent )
            UFG::InventoryComponent::AddQuantity(
              m_pComponent,
              (UFG::eInventoryItemEnum)pTrackEnumBinding.m_EnumValue,
              i_user_data,
              v3);
        }
      }
    }
    v12 = pTrackEnumBinding.mPrev;
    mNext = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    mNext->mPrev = v12;
  }
}

// File Line: 6441
// RVA: 0x50B1D0
void __fastcall UFG::TSCharacter::Mthd_set_unlimited_ammo(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[39].m_pComponent;
    if ( m_pComponent )
      BYTE1(m_pComponent[14].m_pSimObject) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 6462
// RVA: 0x500420
void __fastcall UFG::TSCharacter::Mthd_inventory_create_and_equip(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::SimObject *v6; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      PropertySet = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      if ( PropertySet )
      {
        v6 = this->mpSimObj.m_pPointer;
        if ( !v6 || (v6->m_Flags & 0x4000) == 0 )
          v6 = 0i64;
        UFG::SimObjectUtility::CreateAndAttachProp(PropertySet, v6, 0);
      }
    }
  }
}

// File Line: 6485
// RVA: 0x500660
void __fastcall UFG::TSCharacter::Mthd_inventory_slot_unequip(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::eInventoryEquipSlot EnumFromSymbol; // r9d
  UFG::SimObject *v7; // rdx
  UFG::InventoryComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                       &UFG::gInventoryEquipSlotsTracksEnum,
                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v7 = this->mpSimObj.m_pPointer;
      if ( v7 )
      {
        if ( (v7->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::InventoryComponent *)v7->m_Components.p[39].m_pComponent;
          if ( m_pComponent )
            UFG::InventoryComponent::UnEquip(
              m_pComponent,
              EnumFromSymbol,
              *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
        }
      }
    }
  }
}

// File Line: 6509
// RVA: 0x5005B0
void __fastcall UFG::TSCharacter::Mthd_inventory_slot_set_can_drop(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  UFG::eInventoryEquipSlot EnumFromSymbol; // r9d
  UFG::SimObject *v7; // rdx
  UFG::InventoryComponent *m_pComponent; // rcx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      EnumFromSymbol = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                       &UFG::gInventoryEquipSlotsTracksEnum,
                                       (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v7 = this->mpSimObj.m_pPointer;
      if ( v7 )
      {
        if ( (v7->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::InventoryComponent *)v7->m_Components.p[39].m_pComponent;
          if ( m_pComponent )
            UFG::InventoryComponent::SetCanDrop(
              m_pComponent,
              EnumFromSymbol,
              *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
        }
      }
    }
  }
}

// File Line: 6532
// RVA: 0x500490
void __fastcall UFG::TSCharacter::Mthd_inventory_is_equipped(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // rax
  bool v4; // bl
  int EnumFromSymbol; // r14d
  UFG::eInventoryEquipSlot v9; // eax
  int SlotTarget; // eax
  UFG::SimObject *v11; // rdx
  UFG::TargetingSystemPedPlayerComponent *m_pComponent; // r8
  UFG::SimObject *v13; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  int m_pSimObject; // eax

  m_pPointer = this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      EnumFromSymbol = TracksEnum<unsigned long>::GetEnumFromSymbol(
                         &UFG::gInventoryItemTracksEnum,
                         (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v9 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                           &UFG::gInventoryEquipSlotsTracksEnum,
                           (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64));
      SlotTarget = UFG::InventoryComponent::GetSlotTarget(v9);
      v11 = this->mpSimObj.m_pPointer;
      if ( v11 )
      {
        if ( (v11->m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::TargetingSystemPedPlayerComponent *)v11->m_Components.p[eTARGET_TYPE_EQUIPPED_GLASSES].m_pComponent;
          if ( m_pComponent )
          {
            v13 = m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[SlotTarget]].m_pTarget.m_pPointer;
            if ( v13 )
            {
              ComponentOfType = UFG::SimObject::GetComponentOfType(v13, UFG::InventoryItemComponent::_TypeUID);
              if ( ComponentOfType )
              {
                m_pSimObject = (int)ComponentOfType[1].m_pSimObject;
                v4 = m_pSimObject && EnumFromSymbol == m_pSimObject;
              }
            }
          }
        }
      }
    }
  }
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v4);
}

// File Line: 6572
// RVA: 0x4FFD00
void __fastcall UFG::TSCharacter::Mthd_group_is_leader(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool IsLeader; // dl

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  IsLeader = 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    IsLeader = UFG::GroupComponent::IsLeader(m_pPointer);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(IsLeader);
}

// File Line: 6592
// RVA: 0x4FFB90
void __fastcall UFG::TSCharacter::Mthd_group_is_follower(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool IsFollower; // dl

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  IsFollower = 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    IsFollower = UFG::GroupComponent::IsFollower(m_pPointer);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(IsFollower);
}

// File Line: 6612
// RVA: 0x4FFBF0
void __fastcall UFG::TSCharacter::Mthd_group_is_group_member(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  bool IsGroupMember; // dl

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  IsGroupMember = 0;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    IsGroupMember = UFG::GroupComponent::IsGroupMember(m_pPointer);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(IsGroupMember);
}

// File Line: 6632
// RVA: 0x4FFC50
void __fastcall UFG::TSCharacter::Mthd_group_is_in_my_group(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  char v4; // si
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rbx
  UFG::TSActor *ArgByNameOrInstance; // rax
  UFG::SimObjectGame *v9; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
    {
      GroupComponent = UFG::GroupComponent::GetGroupComponent(m_pPointer);
      if ( GroupComponent )
      {
        ArgByNameOrInstance = UFG::TSActor::GetArgByNameOrInstance(pScope, 0);
        if ( ArgByNameOrInstance )
        {
          v9 = (UFG::SimObjectGame *)ArgByNameOrInstance->mpSimObj.m_pPointer;
          if ( v9 )
          {
            v10 = UFG::GroupComponent::GetGroupComponent(v9);
            if ( v10 )
              v4 = UFG::GroupComponent::IsInGroup((UFG::GroupComponent *)GroupComponent, (UFG::GroupComponent *)v10);
          }
        }
      }
    }
  }
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v4);
}

// File Line: 6676
// RVA: 0x4FF8D0
void __fastcall UFG::TSCharacter::Mthd_group_get_leader(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rax
  UFG::GroupComponent *Leader; // rax
  UFG::SimObject *SimObjectPtr; // rax

  if ( ppResult )
  {
    *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        GroupComponent = UFG::GroupComponent::GetGroupComponent(m_pPointer);
        if ( GroupComponent )
        {
          Leader = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)GroupComponent);
          if ( Leader )
          {
            SimObjectPtr = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(Leader);
            *ppResult = UFG::TSActor::SkookumObjFromSimObj(SimObjectPtr);
          }
        }
      }
    }
  }
}

// File Line: 6707
// RVA: 0x4FF950
void __fastcall UFG::TSCharacter::Mthd_group_get_members(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  unsigned int v5; // ebx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *GroupComponent; // rbp
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v7; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v8; // rdi
  UFG::GroupComponent *Leader; // rax
  UFG::GroupComponent *v10; // r14
  UFG::SimObject *SimObjectPtr; // rax
  UFG::TSActorComponent *ComponentOfType; // rax
  UFG::TSActor *Actor; // rax
  UFG::GroupComponent *Follower; // rax
  UFG::GroupComponent *v15; // rsi
  UFG::SimObject *v16; // rax
  UFG::TSActorComponent *v17; // rax
  UFG::TSActor *v18; // rax
  UFG::GroupComponent *v19; // rsi
  UFG::SimObject *v20; // rax
  UFG::TSActorComponent *v21; // rax
  UFG::TSActor *v22; // rax
  __int64 i_count; // rax
  ARefCountMix<SSInstance> **i_array_p; // rbx
  ARefCountMix<SSInstance> **i; // rsi

  if ( ppResult )
  {
    *ppResult = SSBrain::c_nil_p;
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        v5 = 0;
        if ( (m_pPointer->m_Flags & 0x4000) == 0 )
          m_pPointer = 0i64;
        GroupComponent = UFG::GroupComponent::GetGroupComponent(m_pPointer);
        if ( GroupComponent )
        {
          v7 = (APArray<SSActor,SSActor,ACompareAddress<SSActor> > *)AMemory::c_malloc_func(0x18ui64, "SSList");
          v8 = v7;
          if ( v7 )
          {
            v7->i_count = 0;
            v7->i_array_p = 0i64;
            v7->i_size = 0;
            v7->i_array_p = (SSActor **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
          }
          else
          {
            v8 = 0i64;
          }
          Leader = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)GroupComponent);
          v10 = Leader;
          if ( Leader )
          {
            if ( UFG::GroupComponent::GetSimObjectPtr(Leader) )
            {
              SimObjectPtr = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v10);
              ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                           SimObjectPtr,
                                                           UFG::TSActorComponent::_TypeUID);
              if ( ComponentOfType )
              {
                Actor = UFG::TSActorComponent::GetActor(ComponentOfType);
                APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, Actor);
              }
            }
            if ( Scaleform::Render::Hairliner::GetMeshVertexCount(v10) )
            {
              do
              {
                Follower = UFG::GroupComponent::GetFollower(v10, v5);
                v15 = Follower;
                if ( GroupComponent != (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)Follower )
                {
                  if ( UFG::GroupComponent::GetSimObjectPtr(Follower) )
                  {
                    v16 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v15);
                    v17 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                     v16,
                                                     UFG::TSActorComponent::_TypeUID);
                    if ( v17 )
                    {
                      v18 = UFG::TSActorComponent::GetActor(v17);
                      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, v18);
                    }
                  }
                }
                ++v5;
              }
              while ( v5 < Scaleform::Render::Hairliner::GetMeshVertexCount(v10) );
            }
          }
          else if ( UFG::GroupComponent::IsLeader((UFG::GroupComponent *)GroupComponent)
                 && Scaleform::Render::Hairliner::GetMeshVertexCount((UFG::GroupComponent *)GroupComponent) )
          {
            do
            {
              v19 = UFG::GroupComponent::GetFollower((UFG::GroupComponent *)GroupComponent, v5);
              if ( UFG::GroupComponent::GetSimObjectPtr(v19) )
              {
                v20 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v19);
                v21 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v20, UFG::TSActorComponent::_TypeUID);
                if ( v21 )
                {
                  v22 = UFG::TSActorComponent::GetActor(v21);
                  APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, v22);
                }
              }
              ++v5;
            }
            while ( v5 < Scaleform::Render::Hairliner::GetMeshVertexCount((UFG::GroupComponent *)GroupComponent) );
          }
          i_count = v8->i_count;
          if ( (_DWORD)i_count )
          {
            i_array_p = (ARefCountMix<SSInstance> **)v8->i_array_p;
            for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
              UFG::PersistentData::MapFloat::Iterator::Next(*i_array_p + 4);
          }
          *ppResult = SSList::as_instance((SSList *)v8);
        }
      }
    }
  }
}

// File Line: 6774
// RVA: 0x4FFD60
void __fastcall UFG::TSCharacter::Mthd_group_leave(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      UFG::GroupComponent::LeaveGroup(m_pPointer);
  }
}

// File Line: 6789
// RVA: 0x507870
void __fastcall UFG::TSCharacter::Mthd_set_can_wander(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rax
  UFG::SimObject *m_pPointer; // rdx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer )
  {
    if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      BYTE5(m_pPointer->m_Components.p[22].m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) = i_data_p->i_user_data != 0;
  }
}

// File Line: 6801
// RVA: 0x504B80
void __fastcall UFG::TSCharacter::Mthd_lock_freerun_mode(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSData *v4; // rax
  const char ***p_i_user_data; // r12
  const char ***v6; // r13
  unsigned int v7; // esi
  char v8; // r14
  const char **v9; // rdi
  unsigned int v10; // r15d
  char v11; // bp
  unsigned int i; // ebx
  UFG::SimComponent *m_pSimComponent; // rax

  i_array_p = pScope->i_data.i_array_p;
  v4 = i_array_p[1];
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  v6 = (const char ***)&v4->i_data_p->i_user_data;
  if ( this->mActiveAIEntityComponent.m_pSimComponent
    && (*i_array_p)->i_data_p != (SSInstance *)-32i64
    && v4->i_data_p != (SSInstance *)-32i64 )
  {
    v7 = 0;
    v8 = 0;
    v9 = UFG::gParkourTypeNames;
    v10 = 0;
    v11 = 0;
    for ( i = 0; i < 3; ++i )
    {
      if ( !(unsigned int)UFG::qStringCompareInsensitive(**p_i_user_data, *v9, -1) )
      {
        v7 = i;
        v8 = 1;
      }
      if ( !(unsigned int)UFG::qStringCompareInsensitive(**v6, *v9, -1) )
      {
        v10 = i;
        v11 = 1;
      }
      ++v9;
    }
    if ( v8 )
    {
      if ( v11 )
      {
        m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
        *((_BYTE *)&m_pSimComponent[65].m_SimObjIndex + 2) = 1;
        m_pSimComponent[65].m_NameUID = v7;
        *(_DWORD *)&m_pSimComponent[65].m_Flags = v10;
      }
    }
  }
}

// File Line: 6850
// RVA: 0x50E3C0
void __fastcall UFG::TSCharacter::Mthd_unlock_freerun_mode(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    *((_BYTE *)&m_pSimComponent[65].m_SimObjIndex + 2) = 0;
}

// File Line: 6860
// RVA: 0x50B2B0
void __fastcall UFG::TSCharacter::Mthd_set_vault_success_rate(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *m_pSimComponent; // rcx

  m_pSimComponent = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( m_pSimComponent )
    UFG::ActiveAIEntityComponent::SetParkourSuccessRate(
      m_pSimComponent,
      *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 6872
// RVA: 0x50B240
void __fastcall UFG::TSCharacter::Mthd_set_usable_for_cop_system(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r8
  UFG::SimComponent *m_pComponent; // rdx

  m_pPointer = this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[17].m_pComponent;
    if ( m_pComponent )
      LOBYTE(m_pComponent[7].m_Flags) ^= (LOBYTE(m_pComponent[7].m_Flags) ^ (2
                                                                           * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 2;
  }
}

// File Line: 6921
// RVA: 0x504060
void __fastcall UFG::TSCharacter::Mthd_list_gather_characters(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObject *m_pPointer; // r13
  SSData **i_array_p; // r9
  float v5; // xmm6_4
  int i_user_data; // r15d
  int v7; // r12d
  int v8; // edi
  int v9; // ebx
  int v10; // esi
  int v11; // ebp
  int v12; // r14d
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // r13d
  SSActor **v16; // r8
  SSActorClass *v17; // rax
  float v18; // xmm6_4
  __int64 *v19; // rcx
  __int64 *v20; // rax
  unsigned __int64 v21; // rsi
  __int64 *v22; // r14
  unsigned __int64 v23; // rbp
  SSActor **v24; // rbx
  UFG::TransformNodeComponent *v25; // rax
  unsigned int v26; // eax
  __int64 v27; // rdx
  SSActor **v28; // rax
  SSActor **v29; // rcx
  UFG::SimObjectCVBase *v30; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *v32; // rax
  bool v33; // al
  UFG::TSCharacter *v34; // rcx
  const char **v35; // rcx
  bool v36; // al
  bool IsKnockedOut; // al
  UFG::SimComponent *SimObjectCharacter; // rax
  bool *v39; // rax
  bool v40; // al
  bool v41; // cl
  char *v42; // rdx
  unsigned int v43; // ecx
  unsigned int v44; // edx
  UFG::qBaseTreeRB *v45; // rax
  SSList *v46; // rax
  SSList *v47; // rbx
  __int64 i; // rsi
  SSInstance *v49; // r14
  __int64 i_count; // rdi
  SSInstance **v51; // rbp
  unsigned __int64 v52; // rax
  SSActor **v53; // rax
  __int64 v54; // rax
  ARefCountMix<SSInstance> **v55; // rdi
  ARefCountMix<SSInstance> **j; // rsi
  int v57; // [rsp+20h] [rbp-B8h]
  unsigned int v58; // [rsp+20h] [rbp-B8h]
  unsigned int size; // [rsp+20h] [rbp-B8h]
  SSActor **Src; // [rsp+28h] [rbp-B0h]
  const char **Srca; // [rsp+28h] [rbp-B0h]
  char *Srcb; // [rsp+28h] [rbp-B0h]
  int v63; // [rsp+30h] [rbp-A8h]
  unsigned int v64; // [rsp+30h] [rbp-A8h]
  SSActor **ptr; // [rsp+40h] [rbp-98h]
  int v66; // [rsp+50h] [rbp-88h]
  SSActor **v67; // [rsp+50h] [rbp-88h]
  UFG::qVector3 pos; // [rsp+58h] [rbp-80h] BYREF
  __int64 v69; // [rsp+68h] [rbp-70h]
  const char ***p_i_user_data; // [rsp+70h] [rbp-68h]
  __int64 v71; // [rsp+78h] [rbp-60h]
  float *v73; // [rsp+E8h] [rbp+10h]
  int v75; // [rsp+F8h] [rbp+20h]
  int v76; // [rsp+F8h] [rbp+20h]

  v71 = -2i64;
  m_pPointer = this->mpSimObj.m_pPointer;
  i_array_p = pScope->i_data.i_array_p;
  v5 = *(float *)&(*i_array_p)->i_data_p->i_user_data;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v7 = i_array_p[2]->i_data_p->i_user_data;
  v8 = i_array_p[3]->i_data_p->i_user_data;
  p_i_user_data = (const char ***)&i_array_p[4]->i_data_p->i_user_data;
  v9 = i_array_p[5]->i_data_p->i_user_data;
  v75 = v9;
  v10 = i_array_p[6]->i_data_p->i_user_data;
  v63 = v10;
  v11 = i_array_p[7]->i_data_p->i_user_data;
  v57 = v11;
  v12 = i_array_p[8]->i_data_p->i_user_data;
  v66 = v12;
  if ( m_pPointer )
    m_pPointer = (UFG::SimObject *)m_pPointer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
  v13 = *((float *)m_pPointer[1].mNode.mChild + 1);
  v14 = *(float *)&m_pPointer[1].mNode.mChild[1];
  pos.x = *(float *)m_pPointer[1].mNode.mChild;
  pos.y = v13;
  pos.z = v14;
  v15 = 0;
  v16 = 0i64;
  ptr = 0i64;
  v17 = UFG::SkookumMgr::mspCharacterClass;
  if ( !UFG::SkookumMgr::mspCharacterClass )
    v17 = SSBrain::c_physical_actor_class_p;
  v18 = v5 * v5;
  v19 = (__int64 *)v17->i_instances.i_array_p;
  v20 = &v19[v17->i_instances.i_count];
  if ( v19 < v20 )
  {
    LODWORD(v21) = 0;
    v22 = v19;
    v23 = (unsigned __int64)v20;
    v24 = 0i64;
    do
    {
      v69 = *v22;
      v25 = *(UFG::TransformNodeComponent **)(v69 + 152);
      v73 = (float *)v25;
      if ( v25 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v25);
        if ( (float)((float)((float)((float)(pos.y - v73[45]) * (float)(pos.y - v73[45]))
                           + (float)((float)(pos.x - v73[44]) * (float)(pos.x - v73[44])))
                   + (float)((float)(pos.z - v73[46]) * (float)(pos.z - v73[46]))) <= v18 )
        {
          v26 = v15 + 1;
          if ( (unsigned int)v21 < v15 + 1 )
          {
            Src = v24;
            if ( v15 == -1 )
              LODWORD(v21) = 0;
            else
              v21 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v15 & 0xFFFFFFFC) + 32) >> 3;
            v24 = APArrayBase<SSActor>::alloc_array(v21);
            ptr = v24;
            memmove(v24, Src, 8i64 * v15);
            AMemory::c_free_func(Src);
            v26 = v15 + 1;
          }
          v24[v15] = (SSActor *)v69;
          v15 = v26;
        }
      }
      ++v22;
    }
    while ( (unsigned __int64)v22 < v23 );
    v9 = v75;
    v10 = v63;
    v11 = v57;
    v12 = v66;
    v16 = ptr;
  }
  v27 = v15 - 1;
  v76 = v27;
  if ( (int)v27 >= 0 )
  {
    v28 = &v16[(int)v27];
    v67 = v28;
    while ( *v28 != this )
    {
      v30 = *(UFG::SimObjectCVBase **)&(*v28)[1].i_icoroutines_to_update.i_count;
      if ( i_user_data != qSymbol_dontcare.mUID && v30 )
      {
        m_Flags = v30->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          v32 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v30);
        else
          v32 = (UFG::SimObjectCharacterPropertiesComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v30,
                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 v30,
                                                                 UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
        if ( v32 )
        {
          v33 = v32->m_symFactionClass.mUID == v7;
          if ( i_user_data == qSymbol_exclude.mUID )
            v33 = !v33;
          if ( !v33 )
            goto LABEL_82;
        }
      }
      v34 = this;
      if ( v8 != qSymbol_dontcare.mUID && this->mActiveAIEntityComponent.m_pSimComponent )
      {
        v58 = 0;
        v35 = UFG::AIObjectiveNames;
        Srca = UFG::AIObjectiveNames;
        while ( (unsigned int)UFG::qStringCompareInsensitive(**p_i_user_data, *v35, -1) )
        {
          ++v58;
          v35 = ++Srca;
          if ( v58 >= 0x24 )
          {
            v36 = 0;
            goto LABEL_42;
          }
        }
        v36 = 1;
LABEL_42:
        if ( v8 == qSymbol_exclude.mUID )
          v36 = !v36;
        if ( !v36 )
          goto LABEL_82;
        v34 = this;
      }
      if ( v9 != qSymbol_dontcare.mUID )
      {
        if ( v9 == qSymbol_alive.mUID )
        {
          IsKnockedOut = !UFG::IsKnockedOut((UFG::SimObjectGame *)v34->mpSimObj.m_pPointer);
        }
        else
        {
          if ( v9 != qSymbol_dead.mUID )
            goto LABEL_82;
          IsKnockedOut = UFG::IsKnockedOut((UFG::SimObjectGame *)v34->mpSimObj.m_pPointer);
        }
        if ( !IsKnockedOut )
          goto LABEL_82;
      }
      if ( v11 != qSymbol_dontcare.mUID )
      {
        SimObjectCharacter = (UFG::SimComponent *)UFG::TSCharacter::GetSimObjectCharacter(this);
        if ( SimObjectCharacter )
        {
          SimObjectCharacter = (UFG::SimComponent *)UFG::TSCharacter::GetSimObjectCharacter(this);
          if ( SimObjectCharacter )
            SimObjectCharacter = UFG::TSCharacter::GetSimObjectCharacter(this)->m_Components.p[44].m_pComponent;
          LOBYTE(SimObjectCharacter) = SimObjectCharacter != 0i64;
        }
        if ( v11 != qSymbol_invehicle.mUID )
          LOBYTE(SimObjectCharacter) = (_BYTE)SimObjectCharacter == 0;
        if ( !(_BYTE)SimObjectCharacter )
          goto LABEL_82;
      }
      if ( v12 != qSymbol_dontcare.mUID )
      {
        v39 = PropertyUtils::Get<bool>(
                this->mpSimObj.m_pPointer->m_pSceneObj,
                (UFG::qArray<unsigned long,0> *)&qSymbol_ScenarioControl);
        if ( v39 )
        {
          v40 = *v39;
        }
        else
        {
          PropertyUtils::SetRuntime<bool>(
            this->mpSimObj.m_pPointer->m_pSceneObj,
            (UFG::qArray<unsigned long,0> *)&qSymbol_ScenarioControl,
            0);
          v40 = 0;
        }
        if ( v12 == qSymbol_notscenariocontrol.mUID )
          v40 = !v40;
        if ( !v40 )
          goto LABEL_82;
      }
      if ( v10 != qSymbol_dontcare.mUID )
      {
        v41 = 0;
        size = UFG::TSGameSlice::msInteriorTriggerData.size;
        v64 = 0;
        if ( UFG::TSGameSlice::msInteriorTriggerData.size )
        {
          v42 = 0i64;
          Srcb = 0i64;
          v43 = UFG::TSGameSlice::msInteriorTriggerData.size;
          do
          {
            v44 = *(_DWORD *)&v42[(unsigned __int64)UFG::TSGameSlice::msInteriorTriggerData.p + 8];
            if ( v44 )
            {
              v45 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v44);
              if ( v45
                && v45 != (UFG::qBaseTreeRB *)112
                && UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)v45[1].mNULL.mParent, &pos) )
              {
                v41 = 1;
                goto LABEL_79;
              }
              v43 = size;
            }
            ++v64;
            v42 = Srcb + 168;
            Srcb += 168;
          }
          while ( v64 < v43 );
          v41 = 0;
        }
LABEL_79:
        if ( v10 == qSymbol_outdoors.mUID )
          v41 = !v41;
        if ( !v41 )
        {
LABEL_82:
          --v15;
          LODWORD(v27) = v76;
          v29 = &ptr[v76];
          goto LABEL_83;
        }
      }
LABEL_84:
      v27 = (unsigned int)(v76 - 1);
      v76 = v27;
      v28 = --v67;
      if ( (int)v27 < 0 )
        goto LABEL_85;
      v16 = ptr;
    }
    --v15;
    v29 = &v16[v27];
LABEL_83:
    memmove(v29, v29 + 1, 8i64 * (v15 - (unsigned int)v27));
    goto LABEL_84;
  }
LABEL_85:
  v46 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v47 = v46;
  if ( v46 )
  {
    v46->i_items.i_count = 0;
    v46->i_items.i_array_p = 0i64;
    v46->i_items.i_size = 0;
    v46->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  else
  {
    v47 = 0i64;
  }
  for ( i = (int)(v15 - 1); i >= 0; --i )
  {
    v49 = ptr[i];
    i_count = v47->i_items.i_count;
    if ( v47->i_items.i_size < (unsigned int)(i_count + 1) )
    {
      v51 = v47->i_items.i_array_p;
      if ( (_DWORD)i_count == -1 )
        LODWORD(v52) = 0;
      else
        v52 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)i_count >> 2) + 1)) >> 3;
      v47->i_items.i_size = v52;
      v53 = APArrayBase<SSActor>::alloc_array(v52);
      v47->i_items.i_array_p = v53;
      memmove(v53, v51, 8 * i_count);
      AMemory::c_free_func(v51);
    }
    v47->i_items.i_array_p[i_count] = v49;
    ++v47->i_items.i_count;
  }
  v54 = v47->i_items.i_count;
  if ( (_DWORD)v54 )
  {
    v55 = (ARefCountMix<SSInstance> **)v47->i_items.i_array_p;
    for ( j = &v55[v54]; v55 < j; ++v55 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v55 + 4);
  }
  *ppResult = SSList::as_instance(v47);
  AMemory::c_free_func(ptr);
}

// File Line: 7121
// RVA: 0x504B30
void __fastcall UFG::TSPlayer::Mthd_load_mission_item(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  UFG::qSymbol *i_data_p; // rdi
  bool v5; // bl
  UFG::StoreFrontTracker *v6; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (UFG::qSymbol *)(*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p->i_user_data != 0;
  v6 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadMissionItem(v6, i_data_p + 8, v5);
}

// File Line: 7130
// RVA: 0x503EA0
void __fastcall UFG::TSPlayer::Mthd_is_wearing_preset_outfit(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::ID *Stat; // rax

  if ( ppResult )
  {
    v4 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v4, CurrentOutfit);
    *ppResult = SSBoolean::pool_new(Stat->mValue.mUID != -1);
  }
}

// File Line: 7139
// RVA: 0x4FDAA0
void __fastcall UFG::TSPlayer::Mthd_get_outfit_name(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatTracker *v4; // rax
  ASymbol sym; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    v4 = UFG::GameStatTracker::Instance();
    sym.i_uid = UFG::GameStatTracker::GetStat(v4, CurrentOutfit)->mValue.mUID;
    *ppResult = SSSymbol::as_instance(&sym);
  }
}

// File Line: 7150
// RVA: 0x50E3A0
void __fastcall UFG::TSPlayer::Mthd_unload_mission_items(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::StoreFrontTracker *v3; // rax

  v3 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::ResetEquipment(v3);
}

// File Line: 7158
// RVA: 0x4FCCC0
void __fastcall UFG::TSPlayer::Mthd_get_fashion_value(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::StoreFrontTracker *v4; // rax
  unsigned int ClothingFashionValueTotal; // eax

  if ( ppResult )
  {
    v4 = UFG::StoreFrontTracker::Instance();
    ClothingFashionValueTotal = UFG::StoreFrontTracker::GetClothingFashionValueTotal(v4);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, ClothingFashionValueTotal);
  }
}

// File Line: 7169
// RVA: 0x4FCD00
void __fastcall UFG::TSPlayer::Mthd_get_fashion_value_for_article(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  __int64 i_user_data_low; // rbx
  UFG::StoreFrontTracker *v5; // rax

  if ( ppResult )
  {
    i_user_data_low = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v5 = UFG::StoreFrontTracker::Instance();
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_integer_class_p,
                  (unsigned int)v5->mClothingFashionValue[i_user_data_low]);
  }
}

// File Line: 7187
// RVA: 0x4FC290
void __fastcall UFG::TSPlayer::Mthd_get_clothing_item(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStat::IDStat IDStatEnum; // ebx
  UFG::GameStatTracker *v5; // rax
  ASymbol *Stat; // rax

  if ( ppResult )
  {
    IDStatEnum = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    v5 = UFG::GameStatTracker::Instance();
    Stat = (ASymbol *)UFG::GameStatTracker::GetStat(v5, IDStatEnum);
    *ppResult = SSSymbol::as_instance(Stat);
  }
}

// File Line: 7199
// RVA: 0x501AF0
void __fastcall UFG::TSPlayer::Mthd_is_in_store(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  hkpNullContactMgr *ContactMgr; // rax

  if ( ppResult )
  {
    v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    ContactMgr = hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
    *ppResult = SSBoolean::pool_new(LODWORD(ContactMgr[1].vfptr) != 0);
  }
}

// File Line: 7208
// RVA: 0x501260
void __fastcall UFG::TSPlayer::Mthd_is_combat_meter_activated(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      if ( (m_pPointer->m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::FaceMeterComponent::_TypeUID);
        if ( ComponentOfTypeHK )
          *ppResult = SSBoolean::pool_new(BYTE1(ComponentOfTypeHK[135].m_SafePointerList.mNode.mPrev));
      }
    }
  }
}

// File Line: 7221
// RVA: 0x502410
void __fastcall UFG::TSPlayer::Mthd_is_inside_safe_area(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::CopSystem *v5; // rax
  unsigned __int8 v6; // al
  bool pIsFullyInside; // [rsp+40h] [rbp+18h] BYREF

  if ( ppResult )
  {
    pIsFullyInside = 0;
    v5 = UFG::CopSystem::Instance();
    v6 = (unsigned __int8)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v5, &pIsFullyInside);
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data = pIsFullyInside;
    *ppResult = SSBoolean::pool_new(v6);
  }
}

// File Line: 7235
// RVA: 0x4FDB40
void __fastcall UFG::TSPlayer::Mthd_get_owned_vehicle(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        UFG::TSActor **ppResult)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimObject *v4; // rbx
  UFG::VehicleOwnershipComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *OwnedVehicle; // rax

  if ( ppResult )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0i64;
    if ( m_pPointer
      && (m_pPointer->m_Flags & 0x4000) != 0
      && (ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::VehicleOwnershipComponent::_TypeUID)) != 0i64
      && (OwnedVehicle = UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfTypeHK), (v4 = OwnedVehicle) != 0i64)
      && UFG::SimObjectUtility::IsClassType(OwnedVehicle, &qSymbol_Boat_15) )
    {
      *ppResult = (UFG::TSActor *)SSBrain::c_nil_p;
    }
    else
    {
      *ppResult = UFG::TSActor::SkookumObjFromSimObj(v4);
    }
  }
}

// File Line: 7251
// RVA: 0x505A10
void __fastcall UFG::TSPlayer::Mthd_override_reticle_size(
        UFG::TSPlayer *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimObjectCharacter *m_pPointer; // r8
  UFG::AimingPlayerComponent *v5; // r8
  SSData **i_array_p; // rdx

  m_pPointer = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( m_pPointer && (m_pPointer->m_Flags & 0x4000) != 0 )
    v5 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(m_pPointer);
  else
    v5 = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  if ( (*i_array_p)->i_data_p->i_user_data )
    v5->m_fOverrideReticleSize = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  else
    v5->m_fOverrideReticleSize = -1.0;
}

// File Line: 7272
// RVA: 0x508B70
void __fastcall UFG::TSCharacter::Mthd_set_is_out_of_fight(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // r8

  m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( m_pSimComponent )
    LOBYTE(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) ^= (LOBYTE(m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) ^ (32 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 0x20;
}

// File Line: 7285
// RVA: 0x4FD440
void __fastcall UFG::TSCharacter::Mthd_get_is_out_of_fight(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( m_pSimComponent && ((__int64)m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev & 0x20) != 0 )
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 7298
// RVA: 0x5028E0
void __fastcall UFG::TSCharacter::Mthd_is_out_of_fight(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    m_pSimComponent = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( m_pSimComponent )
      *ppResult = SSBoolean::pool_new((*((_BYTE *)m_pSimComponent + 2096) & 0x20) != 0);
    else
      *ppResult = SSBoolean::pool_new(1);
  }
}

// File Line: 7325
// RVA: 0x501A30
void __fastcall UFG::TSCharacter::Mthd_is_in_fight(
        UFG::TSCharacter *this,
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::SimComponent *m_pSimComponent; // rax

  if ( ppResult )
  {
    if ( UFG::IsKnockedOut((UFG::SimObjectGame *)this->mpSimObj.m_pPointer)
      || (m_pSimComponent = this->mAIScriptInterfaceComponent.m_pSimComponent) == 0i64
      || ((__int64)m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev & 0x20) != 0 )
    {
      *ppResult = SSBoolean::pool_new(0);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(1);
    }
  }
}

// File Line: 7341
// RVA: 0x4D4FF0
void UFG::TSPlayer::BindAtomics(void)
{
  void (__fastcall *v0)(UFG::TSPlayer *, SSInvokedMethod *, SSInstance **); // [rsp+20h] [rbp-10h] BYREF
  int v1; // [rsp+28h] [rbp-8h]

  v0 = UFG::TSPlayer::Mthd_load_mission_item;
  v1 = 0;
  UFG::SkookumMgr::mspPlayerClass = (SSActorClass *)SSBrain::get_class("Player");
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "equip_mission_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_is_wearing_preset_outfit;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "is_wearing_preset_outfit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_get_outfit_name;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "get_outfit_name",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_unload_mission_items;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "reset_equipment",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_get_fashion_value;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "get_fashion_value",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_get_fashion_value_for_article;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "get_fashion_value_for_article",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_get_clothing_item;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "get_clothing_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_is_in_store;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "is_in_store",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_is_combat_meter_activated;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "is_combat_meter_activated",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_is_inside_safe_area;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "is_inside_safe_area",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_get_owned_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "get_owned_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
  v1 = 0;
  v0 = UFG::TSPlayer::Mthd_override_reticle_size;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspPlayerClass,
    "override_reticle_size",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v0,
    SSBindFlag_instance_no_rebind);
}

// File Line: 7368
// RVA: 0x4CF1E0
void UFG::TSCharacter::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-20h]
  ASymbol rebinda; // [rsp+20h] [rbp-20h]
  ASymbol rebindb; // [rsp+20h] [rbp-20h]
  ASymbol rebindc; // [rsp+20h] [rbp-20h]
  void (__fastcall *v4)(AMD_HD3D *); // [rsp+30h] [rbp-10h] BYREF
  int v5; // [rsp+38h] [rbp-8h]

  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_despawn;
  v5 = 0;
  UFG::SkookumMgr::mspCharacterClass = (SSActorClass *)SSBrain::get_class("Character");
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_suspend_option;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_suspend_option",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_invulnerable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_invulnerable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_take_damage;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_take_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_script_control;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_script_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_scripts_during_ai_tree;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_scripts_during_ai_tree",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_player_script_control;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_player_script_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_detailed_on_ground;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_detailed_on_ground",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_lock_player_gameplay_input;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "lock_player_gameplay_input",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_player_gameplay_input_locked;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_player_gameplay_input_locked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_mission_fail_condition_commit_changes;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "mission_fail_condition_commit_changes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_has_fail_conditions;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "has_fail_conditions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_armed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_armed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_armed_with_non_stowable_weapon;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_armed_with_non_stowable_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_armed_with;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_armed_with",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_knocked_out;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_knocked_out",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_killed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_killed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_moving;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_moving",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_invulnerable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_invulnerable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_script_controlled;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_script_controlled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_male;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_male",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_using_a_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_using_a_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_using_the_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_using_the_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_non_player_damage_multiplier;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_non_player_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_non_player_damage_multiplier;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_non_player_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_max_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_max_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_max_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_max_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_min_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_min_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_min_health;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_min_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_health_clamped_to_minimum;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_health_clamped_to_minimum",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_health_clamped_to_minimum;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_health_clamped_to_minimum",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_regenerative_health_rate;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_regenerative_health_rate",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_regenerative_health_ratio;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_regenerative_health_ratio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_move_stop;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "move_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_force_update_targeting;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "force_update_targeting",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_is_tired;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_is_tired",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_attracted_to_pois;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_attracted_to_pois",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_poi_get_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "poi_get_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_poi_use;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "poi_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_poi_stop_using_use;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "poi_stop_using_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_poi_stop_using;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_poi_stop_using",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_AI_behaviour;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_AI_behaviour",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_speed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_speed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_ignore_ambient_stimuli;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_ignore_ambient_stimuli",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_jog;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_jog",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_jog_allowed;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_jog_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_sprint;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_sprint",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_sprint_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_sprint_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_combat_prop_use;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_combat_prop_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_combat_prop_use_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_combat_prop_use_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_action_hijack;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_action_hijack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_action_hijack_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_action_hijack_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_vehicle_exit;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_vehicle_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_vehicle_exit_allowed;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_vehicle_exit_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_vehicle_eject;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_vehicle_eject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_vehicle_eject_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_vehicle_eject_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_vehicle_shooting;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_vehicle_shooting",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_vehicle_shooting_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_vehicle_shooting_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_sneak_attack;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_sneak_attack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_sneak_attack_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_sneak_attack_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_hostage_release;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_hostage_release",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_hostage_release_allowed;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_hostage_release_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_allow_equip_stowed_weapon;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "allow_equip_stowed_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_equip_stowed_weapon_allowed;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_equip_stowed_weapon_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_action_request_enable_all;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "action_request_enable_all",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_action_request_enable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "action_request_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_action_request_disable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "action_request_disable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_free_aim_intention_xform;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_free_aim_intention_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_pathing_on_material;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_pathing_on_material",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_sloppy_freerunning;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_sloppy_freerunning",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_freerunning;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_freerunning",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_xform_to_defend;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_xform_to_defend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_clear_pos_to_defend;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "clear_pos_to_defend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_spawn_npc_density_adjust;
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "spawn_npc_density_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    1,
    rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_spawn_point_density_adjust;
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "spawn_point_density_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    1,
    rebinda);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_spawn_npc_target_count;
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "spawn_npc_target_count",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    1,
    rebindb);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_spawn_npc_off_range;
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "spawn_npc_off_range",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    1,
    rebindc);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_hidden;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_hidden",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_is_hidden;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_is_hidden",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_attack_param_real;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_attack_param_real",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_attack_param_int;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_attack_param_int",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_max_engagement_distance;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_max_engagement_distance",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_engage_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "engage_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_return_to_default_engagement_of_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "return_to_default_engagement_of_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_begin_fleeing;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "begin_fleeing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_stop_fleeing;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "stop_fleeing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_add_supplementary_attack_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "add_supplementary_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_remove_supplementary_attack_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "remove_supplementary_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_add_scary_actor;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "add_scary_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_clear_scary_actors;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "clear_scary_actors",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_collision_avoidance_type;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_collision_avoidance_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_reset_collision_avoidance_type;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "reset_collision_avoidance_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_objective;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_objective;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_objective_and_actor;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_objective_and_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_clear_objective;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "clear_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_start_holding_action_request;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "start_holding_action_request",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_stop_holding_action_request;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "stop_holding_action_request",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_stop_holding_all_action_requests;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "stop_holding_all_action_requests",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_melee_weapon;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_melee_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_firearm;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_firearm",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_firearm_type;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_firearm_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_disable_hostile;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "disable_hostile",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_hostile;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_hostile",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_reset_state;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "reset_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_reset_state_keep_items;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "reset_state_keep_items",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_reinitialize;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "reinitialize",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_grappling_actor;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_grappling_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_a_driver;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_a_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_the_driver;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_the_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_in_trunk;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_in_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_in_the_trunk;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_in_the_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_a_passenger;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_a_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_the_passenger;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_the_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_local_player;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_local_player",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_trunk_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_trunk_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_current_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_current_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_out_of_fight;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_in_fight;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_in_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_bone_visual_damage_amount;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_bone_visual_damage_amount",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_clone_visual_damage;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "clone_visual_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_distance_target;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "distance_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_distance_target_2d;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "distance_target_2d",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_combat_region;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_combat_region",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_can_gain_attack_rights;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_can_gain_attack_rights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_can_gain_attack_rights;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_can_gain_attack_rights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_fake_has_hostage;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_fake_has_hostage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_in_water;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_in_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_paint_effect;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_paint_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_charred_effect;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_charred_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_footstep_override_effect;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_footstep_override_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_invulnerable_to_fire;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_invulnerable_to_fire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_health_ui_state;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_health_ui_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_clear_current_emotion;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "clear_current_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_current_emotion;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_current_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_standing_adjust;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "standing_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_standing_get;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "standing_get",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_standing_get_targets;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "standing_get_targets",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_standing_set;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "standing_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_set_action;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_set_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_set_purchase_item;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_set_purchase_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_get_action;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_get_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_get_action_min_requirement;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_get_action_min_requirement",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_action_auto_completes_objective;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_auto_completes_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_face_meter_set;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_meter_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = _;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_success_state_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_success;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_failure;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_minigame_success;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_minigame_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_minigame_failure;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_minigame_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_greet_success;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_greet_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_greet_failure;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_greet_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_is_action_other_failure;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_is_action_other_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_enable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_toggle_social_icon;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_toggle_social_icon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_minigame_setup;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "minigame_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_is_enabled;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_is_setup;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_is_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_is_minigame_enabled;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_is_minigame_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_is_minigame_setup;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_is_minigame_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_action_clear;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_action_clear",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_get_level;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_get_level",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_meter_enable;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_meter_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_meter_is_enabled;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_meter_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_grant_player_buff;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "grant_player_buff",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_is_player_buff_active;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_player_buff_active",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_is_playing;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_is_playing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_play;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_play",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_stop;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_stop_all_conversations;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_stop_all_conversations",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_interaction_set_should_exit;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_interaction_set_should_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_interaction_should_exit;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_interaction_should_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_set_should_reset;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_set_should_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_should_reset;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_should_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_get_reference;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_get_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_set_reference;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_set_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_has_reference;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_has_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_is_valid;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_is_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_get_last_played;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_get_last_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_set_last_played;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_set_last_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_interaction_has_occurred;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_interaction_has_occurred",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_minigame_finished_playing;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_minigame_finished_playing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_interaction_has_succeeded;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_interaction_has_succeeded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_set_face_action;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_set_face_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_get_face_action;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_get_face_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_set_conversation_state;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_set_conversation_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_get_conversation_state;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_get_conversation_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_has_been_greeted;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_has_been_greeted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_set_greeted;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_set_greeted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_set_requires_greet;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_set_requires_greet",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_set_auto_charge;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_set_auto_charge",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_get_success_state;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_get_success_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_face_get_success_state_as_symbol;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "face_get_success_state_as_symbol",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_dialogue_get_last_conversation_result;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_dialogue_get_last_conversation_result",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_play;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_play",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_stop;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_has_reference;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_has_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_get_reference;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_get_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_set_reference;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_set_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_post_interaction_dialogue_is_valid;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_post_interaction_dialogue_is_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::MthdC_social_combat_fast_talk_get_succeeded;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "social_combat_fast_talk_get_succeeded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_money_adjust;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "money_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_money_get;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "money_get",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_money_set;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "money_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_faction;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_faction",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_faction;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_faction",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_add_follower;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "add_follower",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_equip;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "equip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_unequip;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "unequip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_stow_equipped_firearm;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "stow_equipped_firearm",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_add_to_inventory;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "add_to_inventory",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_unlimited_ammo;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_unlimited_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_inventory_create_and_equip;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "inventory_create_and_equip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_inventory_slot_unequip;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "inventory_slot_unequip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_inventory_slot_set_can_drop;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "inventory_slot_set_can_drop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_inventory_is_equipped;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "inventory_is_equipped",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_race;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_race_index;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_race_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_force_enter_vehicle;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "force_enter_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_force_enter_vehicle_seat;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "force_enter_vehicle_seat",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_force_enter_vehicle_trunk;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "force_enter_vehicle_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_is_leader;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_is_leader",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_is_follower;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_is_follower",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_is_in_my_group;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_is_in_my_group",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_is_group_member;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_is_group_member",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_get_leader;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_get_leader",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_get_members;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_get_members",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_group_leave;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "group_leave",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_can_wander;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_can_wander",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_enable_in_car_reactions;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "enable_in_car_reactions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_lock_freerun_mode;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "lock_freerun_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_unlock_freerun_mode;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "unlock_freerun_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_vault_success_rate;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_vault_success_rate",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_list_gather_characters;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "list_gather_characters",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_is_being_grappled;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "is_being_grappled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_usable_for_cop_system;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_usable_for_cop_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = _;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "toggle_action_tree_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = _;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "toggle_ai_action_tree_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = _;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "toggle_poi_targeting_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_target_to_choose_targets_near;
  v5 = 0;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_target_to_choose_targets_near",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_interacting_with_vehicle_heuristic;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_interacting_with_vehicle_heuristic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_attack_timer;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_attack_timer",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_sync_to_target;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_sync_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_submit_action_request;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_submit_action_request",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_move_to_actor;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_move_to_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_path_to_xform;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_path_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_move_to_xform;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_move_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_move_to_pos;
  v5 = 0;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_move_to_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_path_to_pos;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_path_to_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_path_to_actor;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_path_to_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_path_to_target_type;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_path_to_target_type",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_follow_path_safe;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_follow_path_safe",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_rotate_dir;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_rotate_dir",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_rotate_pos;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_rotate_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_rotate_actor;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_rotate_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_wait_until_outside_vehicle;
  v5 = 0;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_wait_until_outside_vehicle",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSActor::Coro_raycast_to_target;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_raycast_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Coro_wait_until_objective_is_not;
  SSClass::register_coroutine_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "_wait_until_objective_is_not",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_has_taken_damage;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "has_taken_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_get_is_out_of_fight;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "get_is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_is_out_of_fight;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
  v5 = 0;
  v4 = (void (__fastcall *)(AMD_HD3D *))UFG::TSCharacter::Mthd_set_animation_lod_enabled;
  SSClass::register_method_mthd(
    UFG::SkookumMgr::mspCharacterClass,
    "set_animation_lod_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
}SSInstance **))&v4,
    SSBindFlag_instance_no_rebind);
}

