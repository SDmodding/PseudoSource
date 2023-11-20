// File Line: 197
// RVA: 0x4CB860
void __fastcall UFG::TSCharacter::TSCharacter(UFG::TSCharacter *this, ASymbol *name, SSActorClass *pClass)
{
  UFG::TSCharacter *v3; // rbx
  void (__fastcall *v4)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // rax
  void (__fastcall *v5)(UFG::Event *); // [rsp+38h] [rbp-30h]
  void (__fastcall *v6)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+40h] [rbp-28h]
  void (__fastcall *v7)(UFG::Event *); // [rsp+48h] [rbp-20h]
  void (__fastcall *v8)(fastdelegate::FastDelegate1<char const *,void> *, const char *); // [rsp+50h] [rbp-18h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // [rsp+88h] [rbp+20h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v10; // [rsp+88h] [rbp+20h]

  v3 = this;
  SSActor::SSActor((SSActor *)&this->vfptr, name, pClass, 1);
  v3->vfptr = (SSObjectBaseVtbl *)&UFG::TSActor::`vftable';
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v3->mTransformNodeComponent);
  v3->mpComponent = 0i64;
  v3->m_audioController.m_pEvent = 0i64;
  v9 = &v3->mpSimObj;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v3->mpSimObj.m_pPointer = 0i64;
  v3->vfptr = (SSObjectBaseVtbl *)&UFG::TSCharacter::`vftable';
  v3->mModeFlags = 0;
  v3->mTargetThreshold = 0.5;
  v3->mpNavigationThread.i_obj_p = 0i64;
  v3->mpNavigationThread.i_ptr_id = 0;
  v10 = &v3->mpTargetNode;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v3->mpTargetNode.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>(&v3->mActiveAIEntityComponent);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>(&v3->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>(&v3->mAICharacterControllerBaseComponent);
  v3->mpHealthComp = 0i64;
  v3->mSpeed = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
  if ( !registeredStaticEventHandlers_0 )
  {
    v4 = fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction;
    if ( !UFG::TSCharacter::EntityDeathHandler )
      v4 = 0i64;
    v8 = v4;
    v7 = UFG::TSCharacter::EntityDeathHandler;
    v6 = v4;
    v5 = UFG::TSCharacter::EntityDeathHandler;
    UFG::EventDispatcher::Register(
      &UFG::EventDispatcher::mInstance,
      (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v5,
      0x514B87Fu,
      0i64,
      0);
    registeredStaticEventHandlers_0 = 1;
  }
  if ( (SSActorClass *)v3->i_class_p != UFG::SkookumMgr::mspPlayerClass )
    UFG::TSCharacter::EnableScriptControlNPC(v3, 0);
}

// File Line: 218
// RVA: 0x4CBEE0
void __fastcall UFG::TSCharacter::~TSCharacter(UFG::TSCharacter *this)
{
  UFG::TSCharacter *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSCharacter::`vftable';
  UFG::TSCharacter::ClearTarget(this);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAICharacterControllerBaseComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mAIScriptInterfaceComponent);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mActiveAIEntityComponent);
  v2 = &v1->mpTargetNode;
  if ( v1->mpTargetNode.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mpTargetNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mpTargetNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTargetNode.mPrev;
  }
  v1->mpTargetNode.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mpTargetNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mpTargetNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTargetNode.mPrev;
  UFG::TSActor::~TSActor((UFG::TSActor *)&v1->vfptr);
}

// File Line: 228
// RVA: 0x5118D0
UFG::TSCharacter *__fastcall UFG::TSCharacter::find_instance(UFG::qSymbol *instance_name)
{
  UFG::qSymbol *v1; // rdi
  UFG::TSCharacter *v2; // rbx
  UFG::SimObject *v3; // rax
  unsigned __int16 v4; // dx
  UFG::TSActorComponent *v5; // rax
  SSActorClass *v6; // rax
  SSClass *v7; // rcx
  UFG::TSCharacter *result; // rax

  v1 = instance_name;
  v2 = (UFG::TSCharacter *)APSorted<SSActor,ASymbol,ACompareLogical<ASymbol>>::get(
                             (APSorted<SSActor,ASymbol,ACompareLogical<ASymbol> > *)&SSBrain::c_actor_class_p->i_instances.i_count,
                             (ASymbol *)instance_name);
  if ( (v2
     || (v3 = (UFG::SimObject *)UFG::Simulation::GetSimObject(&UFG::gSim, v1)) != 0i64
     && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::TSActorComponent::_TypeUID)) : (v5 = (UFG::TSActorComponent *)v3->m_Components.p[2].m_pComponent)) : (v5 = (UFG::TSActorComponent *)v3->m_Components.p[3].m_pComponent)) : (v5 = (UFG::TSActorComponent *)v3->m_Components.p[4].m_pComponent)) : (v5 = (UFG::TSActorComponent *)v3->m_Components.p[4].m_pComponent),
         v5 && (v2 = (UFG::TSCharacter *)UFG::TSActorComponent::GetActor(v5)) != 0i64))
    && ((v6 = (SSActorClass *)v2->i_class_p, UFG::SkookumMgr::mspCharacterClass == v6)
     || (v7 = v6->i_superclass_p) != 0i64
     && SSClass::is_class(v7, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr)) )
  {
    result = v2;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 317
// RVA: 0x4E16D0
UFG::SimObjectCharacter *__fastcall UFG::TSCharacter::GetSimObjectCharacter(UFG::TSCharacter *this)
{
  UFG::SimObjectCharacter *result; // rax

  result = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !result || !((result->m_Flags >> 14) & 1) )
    result = 0i64;
  return result;
}

// File Line: 382
// RVA: 0x4D98C0
void __fastcall UFG::TSCharacter::ClearTarget(UFG::TSCharacter *this)
{
  unsigned int v1; // eax
  UFG::TSCharacter *v2; // rbx
  UFG::SimComponent *v3; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = this->mModeFlags;
  v2 = this;
  if ( v1 & 1 )
  {
    this->mModeFlags = v1 & 0xFFFFFFFE;
    v3 = this->mpTargetNode.m_pPointer;
    if ( v3 )
      v3->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, 1u);
  }
  v4 = &v2->mpTargetNode;
  if ( v2->mpTargetNode.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v2->mpTargetNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v2->mpTargetNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mpTargetNode.mPrev;
  }
  v2->mpTargetNode.m_pPointer = 0i64;
  v2->mTargetThreshold = 0.5;
}

// File Line: 402
// RVA: 0x4E0740
void __fastcall UFG::TSCharacter::EnableScriptControlNPC(UFG::TSCharacter *this, bool enable)
{
  UFG::TSCharacter *v2; // rbx
  UFG::AIScriptInterfaceComponent *v3; // rcx
  UFG::SimObject *v4; // rdi
  UFG::PedSpawnManager *v5; // rax
  UFG::PedSpawningInfo::eSuspendAction v6; // er8
  UFG::SceneObjectProperties *v7; // rax
  UFG::qPropertySet *v8; // rcx
  bool *v9; // rax

  v2 = this;
  v3 = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
  {
    if ( enable )
    {
      UFG::AIScriptInterfaceComponent::ScriptTaskIncrement(v3);
      v4 = v2->mpSimObj.m_pPointer;
      if ( v4 && !(v2->i_actor_flags & 0x10000) )
      {
        v5 = UFG::PedSpawnManager::GetInstance();
        v6 = Active;
LABEL_16:
        UFG::PedSpawnManager::SetSuspendOption(v5, v4, v6);
        return;
      }
    }
    else if ( v3->m_ScriptTaskRefCount )
    {
      UFG::AIScriptInterfaceComponent::ScriptTaskDecrement(v3);
      if ( !HIDWORD(v2->mAIScriptInterfaceComponent.m_pSimComponent[1].m_SafePointerList.mNode.mNext) )
      {
        v4 = v2->mpSimObj.m_pPointer;
        if ( !v4 || v2->i_actor_flags & 0x10000 )
          v4 = 0i64;
        v7 = v4->m_pSceneObj;
        v8 = v7->mpWritableProperties;
        if ( !v8 )
          v8 = v7->mpConstProperties;
        v9 = PropertyUtils::Get<bool>(v8, (UFG::qSymbol *)&qSymbol_CanSuspend.mUID, DEPTH_RECURSE);
        if ( v9 )
        {
          if ( *v9 )
          {
            v5 = UFG::PedSpawnManager::GetInstance();
            v6 = 0;
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
  bool v2; // di
  UFG::TSActorComponent *v3; // rcx
  UFG::TSActor *v4; // rax
  UFG::TSActor *v5; // rbx

  v2 = enable;
  if ( (pSimObject->m_Flags >> 14) & 1 )
  {
    if ( (v3 = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent, (v4 = v3->mpActor.i_obj_p) != 0i64)
      && v3->mpActor.i_ptr_id == v4->i_ptr_id
      || enable )
    {
      v5 = UFG::TSActorComponent::GetActor(v3);
      if ( (SSActorClass *)v5->i_class_p == UFG::SkookumMgr::mspPlayerClass )
      {
        UFG::TSCharacter::EnableScriptControlNPC((UFG::TSCharacter *)v5, v2);
        v5->i_actor_flags |= 4u;
      }
      else
      {
        UFG::TSCharacter::EnableScriptControlNPC((UFG::TSCharacter *)v5, v2);
      }
    }
  }
}

// File Line: 506
// RVA: 0x4E21D0
bool __fastcall UFG::TSCharacter::IsAtTarget(UFG::TSCharacter *this)
{
  UFG::SimObject *v1; // rdx
  UFG::TSCharacter *v2; // rdi
  UFG::NavComponent *v3; // rcx
  UFG::SimComponent *v5; // rsi
  UFG::SimComponent *v6; // rbx
  float v7; // xmm2_4
  float v8; // xmm1_4

  v1 = this->mpSimObj.m_pPointer;
  v2 = this;
  if ( v1 && (v1->m_Flags >> 14) & 1 )
  {
    if ( !v1 || !((v1->m_Flags >> 14) & 1) )
      v1 = 0i64;
    v3 = (UFG::NavComponent *)v1->m_Components.p[36].m_pComponent;
    if ( v3 )
      return UFG::NavComponent::IsAtDestination(v3);
  }
  v5 = v2->mpTargetNode.m_pPointer;
  if ( !v5 || !v2->mTransformNodeComponent.m_pSimComponent )
    return 0;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mpTargetNode.m_pPointer);
  v6 = v2->mTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mTransformNodeComponent.m_pSimComponent);
  v7 = *((float *)&v6[2].m_BoundComponentHandles.mNode.mPrev + 1)
     - *((float *)&v5[2].m_BoundComponentHandles.mNode.mPrev + 1);
  v8 = *(float *)&v6[2].m_BoundComponentHandles.mNode.mPrev - *(float *)&v5[2].m_BoundComponentHandles.mNode.mPrev;
  return (float)(v2->mTargetThreshold * v2->mTargetThreshold) > (float)((float)(v7 * v7) + (float)(v8 * v8));
}

// File Line: 541
// RVA: 0x50FD50
void __fastcall UFG::TSCharacter::SetTarget(UFG::TSCharacter *this, UFG::TransformNodeComponent *transNode, UFG::qVector3 *offset, __int64 isOffsetLocalCoords, float thresholdRadius)
{
  UFG::qVector3 *v5; // rbp
  UFG::TransformNodeComponent *v6; // rsi
  UFG::TSCharacter *v7; // rbx
  unsigned int v8; // eax
  UFG::SimComponent *v9; // rcx
  UFG::qMemoryPool *v10; // rax
  UFG::allocator::free_link *v11; // rdi
  unsigned int v12; // eax
  UFG::SimComponent *v13; // rax
  UFG::SimComponent *v14; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qMatrix44 m; // [rsp+40h] [rbp-48h]

  v5 = offset;
  v6 = transNode;
  v7 = this;
  v8 = this->mModeFlags;
  if ( v8 & 1 )
  {
    this->mModeFlags = v8 & 0xFFFFFFFE;
    v9 = this->mpTargetNode.m_pPointer;
    if ( v9 )
      ((void (__fastcall *)(UFG::SimComponent *, signed __int64, UFG::qVector3 *, __int64))v9->vfptr->__vecDelDtor)(
        v9,
        1i64,
        offset,
        isOffsetLocalCoords);
  }
  v10 = UFG::GetSimulationMemoryPool();
  v11 = UFG::qMemoryPool::Allocate(v10, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
  if ( v11 )
  {
    v12 = UFG::qStringHash32("TargetNode", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v11, v12, v6, 0);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = &v7->mpTargetNode;
  if ( v7->mpTargetNode.m_pPointer )
  {
    v16 = v15->mPrev;
    v17 = v7->mpTargetNode.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v7->mpTargetNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mpTargetNode.mPrev;
  }
  v7->mpTargetNode.m_pPointer = v14;
  if ( v14 )
  {
    v18 = v14->m_SafePointerList.mNode.mPrev;
    v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    v15->mPrev = v18;
    v7->mpTargetNode.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  }
  v7->mModeFlags |= 1u;
  m.v0 = UFG::qMatrix44::msIdentity.v0;
  m.v1 = UFG::qMatrix44::msIdentity.v1;
  m.v2 = UFG::qMatrix44::msIdentity.v2;
  m.v3.x = v5->x;
  m.v3.y = v5->y;
  m.v3.z = v5->z;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetLocalTransform((UFG::TransformNodeComponent *)v7->mpTargetNode.m_pPointer, &m);
  if ( thresholdRadius <= 0.5 )
    v7->mTargetThreshold = UFG::gMinArriveThresholdRadius;
  else
    v7->mTargetThreshold = thresholdRadius;
}

// File Line: 575
// RVA: 0x50FEF0
void __fastcall UFG::TSCharacter::SetTarget(UFG::TSCharacter *this, UFG::qVector3 *pos, float thresholdRadius)
{
  float v3; // xmm9_4
  UFG::qVector3 *v4; // rsi
  UFG::TSCharacter *v5; // rdi
  unsigned int v6; // eax
  UFG::SimComponent *v7; // rcx
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  unsigned int v10; // eax
  UFG::SimComponent *v11; // rax
  UFG::SimComponent *v12; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float *v20; // rbx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  UFG::qMatrix44 m; // [rsp+40h] [rbp-88h]

  v3 = thresholdRadius;
  v4 = pos;
  v5 = this;
  v6 = this->mModeFlags;
  if ( v6 & 1 )
  {
    this->mModeFlags = v6 & 0xFFFFFFFE;
    v7 = this->mpTargetNode.m_pPointer;
    if ( v7 )
      v7->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v7->vfptr, 1u);
  }
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x110ui64, "TransformNodeComponent", 0i64, 1u);
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
  v13 = &v5->mpTargetNode;
  if ( v5->mpTargetNode.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v5->mpTargetNode.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v5->mpTargetNode.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mpTargetNode.mPrev;
  }
  v5->mpTargetNode.m_pPointer = v12;
  if ( v12 )
  {
    v16 = v12->m_SafePointerList.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v16;
    v5->mpTargetNode.mNext = &v12->m_SafePointerList.mNode;
    v12->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  v5->mModeFlags |= 1u;
  v17 = v4->x;
  v18 = v4->y;
  v19 = v4->z;
  v20 = (float *)v5->mpTargetNode.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->mpTargetNode.m_pPointer);
  v21 = v20[33];
  v22 = v20[34];
  v23 = v20[35];
  m.v0.x = v20[32];
  m.v0.y = v21;
  m.v0.z = v22;
  m.v0.w = v23;
  v24 = v20[37];
  v25 = v20[38];
  v26 = v20[39];
  m.v1.x = v20[36];
  m.v1.y = v24;
  m.v1.z = v25;
  m.v1.w = v26;
  v27 = v20[41];
  v28 = v20[42];
  v29 = v20[43];
  m.v2.x = v20[40];
  m.v2.y = v27;
  m.v2.z = v28;
  m.v2.w = v29;
  m.v3.x = v17;
  m.v3.y = v18;
  m.v3.z = v19;
  LODWORD(m.v3.w) = (_DWORD)FLOAT_1_0;
  UFG::TransformNodeComponent::SetWorldTransform((UFG::TransformNodeComponent *)v5->mpTargetNode.m_pPointer, &m);
  if ( v3 <= 0.5 )
    v5->mTargetThreshold = UFG::gMinArriveThresholdRadius;
  else
    v5->mTargetThreshold = v3;
}

// File Line: 700
// RVA: 0x50E7B0
void __fastcall UFG::TSCharacter::NavigationScriptFinish(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // r8

  v2 = this->mpNavigationThread.i_obj_p;
  if ( v2 == pScope || !pScope && v2->i_ptr_id != this->mpNavigationThread.i_ptr_id )
  {
    this->mpNavigationThread.i_obj_p = 0i64;
    this->mpNavigationThread.i_ptr_id = 0;
  }
}

// File Line: 723
// RVA: 0x50EB70
void __fastcall UFG::TSCharacter::OnInit(UFG::TSCharacter *this, UFG::SimObject *pSimObj)
{
  UFG::TSCharacter *v2; // rbx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v3; // rcx
  UFG::SimObjectCharacter *v4; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v9; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  char v14; // dl
  UFG::SimObject *v15; // rax

  v2 = this;
  v3 = &this->mActiveAIEntityComponent;
  v4 = (UFG::SimObjectCharacter *)pSimObj;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::ActiveAIEntityComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0>::BindInternal<UFG::SimObjectCharacter>(v3, v4);
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0>::Bind<UFG::SimObjectCharacter>(
    &v2->mAIScriptInterfaceComponent,
    v4);
  v9 = &v2->mAICharacterControllerBaseComponent;
  if ( v2->mAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mAICharacterControllerBaseComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v2->mAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAICharacterControllerBaseComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_15;
  }
  if ( v2->mAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v2->mAICharacterControllerBaseComponent.mNext != &v2->mAICharacterControllerBaseComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mAICharacterControllerBaseComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_14;
  }
LABEL_15:
  v2->mAICharacterControllerBaseComponent.m_Changed = 1;
  v2->mAICharacterControllerBaseComponent.m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v2->mAICharacterControllerBaseComponent.m_TypeUID = UFG::AICharacterControllerBaseComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0>::BindInternal<UFG::SimObjectCharacter>(
    &v2->mAICharacterControllerBaseComponent,
    v4);
  v2->mpHealthComp = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
  UFG::TSActor::OnInit((UFG::TSActor *)&v2->vfptr, (UFG::SimObject *)&v4->vfptr);
  v14 = PropertyUtils::Get<bool>(v4->m_pSceneObj, (UFG::qSymbol *)&qSymbol_SkookumControl.mUID)->mFlags;
  v15 = v2->mpSimObj.m_pPointer;
  if ( v15 && (v15->m_Flags >> 14) & 1 )
  {
    if ( (SSActorClass *)v2->i_class_p == UFG::SkookumMgr::mspPlayerClass )
    {
      UFG::TSCharacter::EnableScriptControlNPC(v2, v14);
      v2->i_actor_flags |= 4u;
    }
    else
    {
      UFG::TSCharacter::EnableScriptControlNPC(v2, v14);
    }
  }
}

// File Line: 740
// RVA: 0x50E940
void __fastcall UFG::TSCharacter::OnDeinit(UFG::TSCharacter *this)
{
  UFG::SimObject *v1; // rdx
  UFG::TSCharacter *v2; // rbx
  UFG::FaceActionComponent *v3; // rcx
  UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *v9; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rax
  UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *v14; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rax

  v1 = this->mpSimObj.m_pPointer;
  v2 = this;
  if ( v1 && (v1->m_Flags >> 14) & 1 )
  {
    if ( !v1 || !((v1->m_Flags >> 14) & 1) )
      v1 = 0i64;
    v3 = (UFG::FaceActionComponent *)v1->m_Components.p[45].m_pComponent;
    if ( v3 )
      UFG::FaceActionComponent::StopAllConversations(v3);
  }
  v4 = &v2->mActiveAIEntityComponent;
  if ( v2->mActiveAIEntityComponent.m_pSimComponent )
  {
    v5 = v4->mPrev;
    v6 = v2->mActiveAIEntityComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mActiveAIEntityComponent.m_pSimComponent = 0i64;
LABEL_14:
    v2->mActiveAIEntityComponent.m_pSimObject = 0i64;
    v2->mActiveAIEntityComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mActiveAIEntityComponent.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_15;
  }
  if ( v2->mActiveAIEntityComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::ActiveAIEntityComponent,0> *)v2->mActiveAIEntityComponent.mNext != &v2->mActiveAIEntityComponent) )
  {
    v7 = v4->mPrev;
    v8 = v2->mActiveAIEntityComponent.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_14;
  }
LABEL_15:
  v2->mActiveAIEntityComponent.m_Changed = 1;
  v9 = &v2->mAIScriptInterfaceComponent;
  if ( v2->mAIScriptInterfaceComponent.m_pSimComponent )
  {
    v10 = v9->mPrev;
    v11 = v2->mAIScriptInterfaceComponent.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v2->mAIScriptInterfaceComponent.m_pSimComponent = 0i64;
LABEL_21:
    v2->mAIScriptInterfaceComponent.m_pSimObject = 0i64;
    v2->mAIScriptInterfaceComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAIScriptInterfaceComponent.mPrev;
    v9->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v9->mPrev;
    goto LABEL_22;
  }
  if ( v2->mAIScriptInterfaceComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v9->mPrev != v9
     || (UFG::RebindingComponentHandle<UFG::AIScriptInterfaceComponent,0> *)v2->mAIScriptInterfaceComponent.mNext != &v2->mAIScriptInterfaceComponent) )
  {
    v12 = v9->mPrev;
    v13 = v2->mAIScriptInterfaceComponent.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    goto LABEL_21;
  }
LABEL_22:
  v2->mAIScriptInterfaceComponent.m_Changed = 1;
  v14 = &v2->mAICharacterControllerBaseComponent;
  if ( v2->mAICharacterControllerBaseComponent.m_pSimComponent )
  {
    v15 = v14->mPrev;
    v16 = v2->mAICharacterControllerBaseComponent.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v2->mAICharacterControllerBaseComponent.m_pSimComponent = 0i64;
LABEL_28:
    v2->mAICharacterControllerBaseComponent.m_pSimObject = 0i64;
    v2->mAICharacterControllerBaseComponent.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mAICharacterControllerBaseComponent.mPrev;
    v14->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v14->mPrev;
    goto LABEL_29;
  }
  if ( v2->mAICharacterControllerBaseComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v14->mPrev != v14
     || (UFG::RebindingComponentHandle<UFG::AICharacterControllerBaseComponent,0> *)v2->mAICharacterControllerBaseComponent.mNext != &v2->mAICharacterControllerBaseComponent) )
  {
    v17 = v14->mPrev;
    v18 = v2->mAICharacterControllerBaseComponent.mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    goto LABEL_28;
  }
LABEL_29:
  v2->mAICharacterControllerBaseComponent.m_Changed = 1;
  UFG::TSActor::OnDeinit((UFG::TSActor *)&v2->vfptr);
}

// File Line: 767
// RVA: 0x4DF470
void __fastcall UFG::TSCharacter::Despawn(UFG::TSCharacter *this, bool waitUntilSuspended)
{
  UFG::SimObjectCharacter *v2; // rbx
  bool v3; // si
  UFG::TSCharacter *v4; // rdi
  UFG::PedSpawnManager *v5; // rax
  UFG::PedSpawningInfo::eSuspendAction v6; // er8

  v2 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  v3 = waitUntilSuspended;
  v4 = this;
  if ( v2 && v2 != UFG::GetLocalPlayer() )
  {
    SSActor::enable_behavior((SSActor *)&v4->vfptr, 0);
    if ( v3 )
    {
      v5 = UFG::PedSpawnManager::GetInstance();
      v6 = 4;
    }
    else
    {
      if ( !(v4->i_actor_flags & 0x10000) )
      {
        UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)&v2->vfptr);
        return;
      }
      v5 = UFG::PedSpawnManager::GetInstance();
      v6 = 8;
    }
    UFG::PedSpawnManager::SetSuspendOption(v5, (UFG::SimObject *)&v2->vfptr, v6);
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
void __fastcall UFG::TSCharacter::Mthd_set_suspend_option(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdi
  UFG::PedSpawningInfo::eSuspendAction v4; // ebx
  UFG::PedSpawnManager *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( !(this->i_actor_flags & 0x10000) )
    {
      v4 = (unsigned int)UFG::PedSpawningInfo::ConvertSymbolToSuspendActionEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v5 = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::SetSuspendOption(v5, v3, v4);
    }
  }
}

// File Line: 839
// RVA: 0x4F2040
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_density_adjust(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::AdjustPedDensity(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  UFG::PedSpawnManager::UpdateDensityOfActiveZones();
}

// File Line: 847
// RVA: 0x4F2240
void __fastcall UFG::TSCharacter::MthdC_spawn_point_density_adjust(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::AdjustSpawnPointDensityModifier(*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 858
// RVA: 0x4F20A0
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_target_count(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PedSpawnManager::SetTargetPedCount((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 868
// RVA: 0x4F2070
void __fastcall UFG::TSCharacter::MthdC_spawn_npc_off_range(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rcx
  SSInstance *v4; // rdx
  SSInstance *v5; // rcx
  __int128 v6; // xmm1
  __int128 v7; // xmm0

  v3 = pScope->i_data.i_array_p;
  v4 = v3[1]->i_data_p;
  v5 = (*v3)->i_data_p;
  v6 = LODWORD(v4->i_user_data);
  v7 = LODWORD(v5->i_user_data);
  _((AMD_HD3D *)v5);
}

// File Line: 876
// RVA: 0x501720
void __fastcall UFG::TSCharacter::Mthd_is_hidden(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 && (v3->m_Flags >> 14) & 1 && (v4 = v3->m_Components.p[14].m_pComponent) != 0i64 && LOBYTE(v4[19].m_TypeUID) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 886
// RVA: 0x508A10
void __fastcall UFG::TSCharacter::Mthd_set_is_hidden(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::CompositeDrawableComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = (UFG::CompositeDrawableComponent *)v3->m_Components.p[14].m_pComponent;
    if ( v4 )
      UFG::CompositeDrawableComponent::SetIsHidden(v4, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 900
// RVA: 0x4F8CB0
void __fastcall UFG::TSCharacter::Mthd_enable_invulnerable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // r9
  SSInvokedMethod *v4; // r10
  UFG::SimObject *v5; // rax
  UFG::SimObject *v6; // rcx
  UFG::SimComponent *v7; // rdx

  v3 = this->mpHealthComp;
  v4 = pScope;
  if ( v3 )
  {
    v5 = this->mpSimObj.m_pPointer;
    if ( v5 )
    {
      if ( (v5->m_Flags >> 14) & 1 )
      {
        v3->m_bIsInvulnerable = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
        v6 = this->mpSimObj.m_pPointer;
        if ( v6 )
        {
          if ( (v6->m_Flags >> 14) & 1 )
          {
            v7 = v6->m_Components.p[38].m_pComponent;
            if ( v7 )
              LOBYTE(v7[1].m_SafePointerList.mNode.mNext) = (*v4->i_data.i_array_p)->i_data_p->i_user_data != 0;
          }
        }
      }
    }
  }
}

// File Line: 922
// RVA: 0x4F9240
void __fastcall UFG::TSCharacter::Mthd_enable_take_damage(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // r8
  UFG::SimObject *v4; // rax

  v3 = this->mpHealthComp;
  if ( v3 )
  {
    v4 = this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 )
        v3->m_bIsTakingDamage = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    }
  }
}

// File Line: 936
// RVA: 0x4F9130
void __fastcall UFG::TSCharacter::Mthd_enable_scripts_during_ai_tree(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
    this->mModeFlags |= 4u;
  else
    this->mModeFlags &= 0xFFFFFFFB;
}

// File Line: 946
// RVA: 0x4F9110
void __fastcall UFG::TSCharacter::Mthd_enable_script_control(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter::EnableScriptControlNPC(this, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 956
// RVA: 0x4F90F0
void __fastcall UFG::TSCharacter::Mthd_enable_player_script_control(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter::EnablePlayerScriptControl(this, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
}

// File Line: 968
// RVA: 0x4F8A10
void __fastcall UFG::TSCharacter::Mthd_enable_detailed_on_ground(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v3; // rax
  UFG::SimObject *v4; // rdx
  UFG::CharacterPhysicsComponent *v5; // rcx

  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    v5 = (UFG::CharacterPhysicsComponent *)v4->m_Components.p[27].m_pComponent;
    if ( v5 )
    {
      JUMPOUT(v3->i_user_data != 0, 0, UFG::CharacterPhysicsComponent::EnableDetailedOnGroundCheck);
      UFG::CharacterPhysicsComponent::DisableDetailedOnGroundCheck(v5);
    }
  }
}

// File Line: 991
// RVA: 0x504CA0
void __fastcall UFG::TSCharacter::Mthd_lock_player_gameplay_input(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData *v3; // rcx

  v3 = *pScope->i_data.i_array_p;
  JUMPOUT(v3->i_data_p->i_user_data, 0i64, UFG::UI::LockGameplayInput);
  UFG::UI::UnlockGameplayInput((UFG::UI *)v3);
}

// File Line: 1004
// RVA: 0x502A20
void __fastcall UFG::TSCharacter::Mthd_is_player_gameplay_input_locked(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UI::gUIInputLocked != 0);
}

// File Line: 1023
// RVA: 0x4E06D0
void __fastcall UFG::TSCharacter::EnablePlayerScriptControl(UFG::TSCharacter *this, bool enable)
{
  bool v2; // di
  UFG::TSCharacter *v3; // rbx
  UFG::SimObject *v4; // rax

  v2 = enable;
  v3 = this;
  if ( enable )
    UFG::UI::LockGameplayInput((UFG::UI *)this);
  else
    UFG::UI::UnlockGameplayInput((UFG::UI *)this);
  v4 = v3->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( (SSActorClass *)v3->i_class_p == UFG::SkookumMgr::mspPlayerClass )
    {
      UFG::TSCharacter::EnableScriptControlNPC(v3, v2);
      v3->i_actor_flags |= 4u;
    }
    else
    {
      UFG::TSCharacter::EnableScriptControlNPC(v3, v2);
    }
  }
}

// File Line: 1047
// RVA: 0x504D40
void __fastcall UFG::TSCharacter::Mthd_mission_fail_condition_commit_changes(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v3; // rax
  UFG::SimObject *v4; // rdx

  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v3 )
    v3 = (SSInstance *)((char *)v3 - 24);
  v4 = this->mpSimObj.m_pPointer;
  if ( !v4 || !((v4->m_Flags >> 14) & 1) )
    v4 = 0i64;
  UFG::MissionFailConditionComponent::HandleAttachment(*(UFG::GameSlice **)&v3[3].i_ptr_id, v4, 0i64);
}

// File Line: 1053
// RVA: 0x4FFDA0
void __fastcall UFG::TSCharacter::Mthd_has_fail_conditions(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
      v4 = v3->m_Components.p[8].m_pComponent;
    else
      v4 = 0i64;
    *ppResult = (SSInstance *)SSBoolean::pool_new(v4 != 0i64);
  }
}

// File Line: 1067
// RVA: 0x1536470
__int64 UFG::_dynamic_initializer_for__gsymGrapRCV__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("GrapRCV", 0xFFFFFFFF);
  UFG::gsymGrapRCV.mUID = result;
  return result;
}

// File Line: 1068
// RVA: 0x1536450
__int64 UFG::_dynamic_initializer_for__gsymGrapAttacks__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Attacks", 0xFFFFFFFF);
  UFG::gsymGrapAttacks.mUID = result;
  return result;
}

// File Line: 1071
// RVA: 0x500D40
void __fastcall UFG::TSCharacter::Mthd_is_being_grappled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // bp
  SSActor *v4; // rdi
  SSInstance **v5; // r14
  UFG::TSCharacter *v6; // rsi
  SSClass *v7; // rbx
  SSActorClass *v8; // rax
  SSClass *v9; // rcx
  UFG::SimObject *v10; // rcx
  UFG::SimComponent *v11; // rbx
  unsigned __int8 v12; // al
  UFG::SimObject *v13; // rcx

  if ( ppResult )
  {
    v3 = 0;
    v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
    v5 = ppResult;
    v6 = this;
    if ( !v4 )
      goto LABEL_18;
    v7 = v4->i_class_p;
    if ( !v7->vfptr->is_actor_class((SSClassDescBase *)&v7->vfptr) )
    {
      if ( v7 != SSBrain::c_symbol_class_p || LODWORD(v4->i_user_data) == -1 )
        goto LABEL_18;
      v4 = SSActor::find((ASymbol *)&v4->i_user_data);
    }
    if ( v4 )
    {
      v8 = (SSActorClass *)v4->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == v8
        || (v9 = v8->i_superclass_p) != 0i64
        && SSClass::is_class(v9, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
      {
        v10 = v6->mpSimObj.m_pPointer;
        if ( v10 && (v10->m_Flags >> 14) & 1 )
          v11 = v10->m_Components.p[7].m_pComponent;
        else
          v11 = 0i64;
        if ( ActionController::IsPlaying((ActionController *)&v11[3], &UFG::gsymGrapAttacks, 0xFFFFFFFF, 1) )
        {
          v12 = UFG::TSCharacter::_is_grappling_actor(
                  v6,
                  *(UFG::SimObject **)&v4[1].i_icoroutines_to_update.i_count,
                  v6->mpSimObj.m_pPointer);
LABEL_24:
          v3 = v12;
$done_3:
          *v5 = (SSInstance *)SSBoolean::pool_new(v3);
          return;
        }
        if ( v11 )
        {
LABEL_23:
          v12 = ActionController::IsPlaying((ActionController *)&v11[3], &UFG::gsymGrapRCV, 0xFFFFFFFF, 1);
          goto LABEL_24;
        }
      }
    }
LABEL_18:
    v13 = v6->mpSimObj.m_pPointer;
    if ( v13 && (v13->m_Flags >> 14) & 1 )
      v11 = v13->m_Components.p[7].m_pComponent;
    else
      v11 = 0i64;
    if ( !v11 )
      goto $done_3;
    goto LABEL_23;
  }
}

// File Line: 1111
// RVA: 0x500950
void __fastcall UFG::TSCharacter::Mthd_is_armed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  bool v5; // r8
  UFG::SimComponent *v6; // rdx
  UFG::SimObject *v7; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = 0;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( v3 )
        {
          if ( (v3->m_Flags >> 14) & 1 )
          {
            v6 = v3->m_Components.p[20].m_pComponent;
            if ( v6 )
            {
              v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 25i64)
                                      + *(_QWORD *)&v6[1].m_TypeUID
                                      + 40);
              if ( v7 )
                v5 = UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID) != 0i64;
            }
          }
        }
      }
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 1144
// RVA: 0x500CA0
void __fastcall UFG::TSCharacter::Mthd_is_armed_with_non_stowable_weapon(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // bl
  SSInstance **v5; // rdi
  UFG::SimComponent *v6; // rdx
  UFG::SimObject *v7; // rcx
  UFG::GunComponent *v8; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( v3 )
        {
          if ( (v3->m_Flags >> 14) & 1 )
          {
            v6 = v3->m_Components.p[20].m_pComponent;
            if ( v6 )
            {
              v7 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 25i64)
                                      + *(_QWORD *)&v6[1].m_TypeUID
                                      + 40);
              if ( v7 )
              {
                v8 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v7, UFG::GunComponent::_TypeUID);
                if ( v8 )
                  v4 = (unsigned __int8)UFG::GunComponent::IsStowable(v8) == 0;
              }
            }
          }
        }
      }
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1180
// RVA: 0x5009E0
void __fastcall UFG::TSCharacter::Mthd_is_armed_with(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  char v4; // bl
  SSInstance **v5; // rdi
  UFG::SimComponent *v6; // rcx
  int v7; // eax
  UFG::SimObjectCharacter *v8; // rax
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rdx
  UFG::SimComponent *v11; // rax
  UFG::SimObjectProp *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimObjectWeaponPropertiesComponent *v14; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( v3 )
        {
          if ( (v3->m_Flags >> 14) & 1 )
          {
            v6 = v3->m_Components.p[39].m_pComponent;
            if ( v6 )
            {
              v7 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
              v4 = v7 == qSymbol_knife.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 9 || SLODWORD(v6[2].vfptr) > 0)
                || v7 == qSymbol_beer_bottle.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 3 || SLODWORD(v6[1].m_pSimObject) > 0)
                || v7 == qSymbol_baton.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 4 || SHIDWORD(v6[1].m_pSimObject) > 0)
                || v7 == qSymbol_cleaver.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 8
                 || SHIDWORD(v6[1].m_BoundComponentHandles.mNode.mNext) > 0)
                || v7 == qSymbol_coke_can.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 1 || *(_DWORD *)&v6[1].m_Flags > 0)
                || v7 == qSymbol_briefcase.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 79 || (signed int)v6[6].m_TypeUID > 0)
                || v7 == qSymbol_broom_full.mUID
                && (LOBYTE(v6[14].m_pSimObject) && *(_DWORD *)&v6[14].m_Flags == 7
                 || SLODWORD(v6[1].m_BoundComponentHandles.mNode.mNext) > 0);
              if ( v7 == qSymbol_camera.mUID )
              {
                v8 = UFG::GetLocalPlayer();
                if ( v8 )
                {
                  v9 = v8->m_Flags;
                  if ( (v9 >> 14) & 1 )
                  {
                    v10 = v8->m_Components.p[20].m_pComponent;
                  }
                  else if ( (v9 & 0x8000u) == 0 )
                  {
                    if ( (v9 >> 13) & 1 )
                    {
                      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    else if ( (v9 >> 12) & 1 )
                    {
                      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    else
                    {
                      v11 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    v10 = v11;
                  }
                  else
                  {
                    v10 = v8->m_Components.p[20].m_pComponent;
                  }
                  if ( v10 )
                  {
                    v12 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + 25i64)
                                                 + *(_QWORD *)&v10[1].m_TypeUID
                                                 + 40);
                    if ( v12 )
                    {
                      v13 = v12->m_Flags;
                      if ( (v13 >> 14) & 1 )
                      {
                        v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                      }
                      else if ( (v13 & 0x8000u) == 0 )
                      {
                        if ( (v13 >> 13) & 1 )
                        {
                          v14 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v12);
                        }
                        else if ( (v13 >> 12) & 1 )
                        {
                          v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v12->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                        else
                        {
                          v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                             (UFG::SimObject *)&v12->vfptr,
                                                                             UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                        }
                      }
                      else
                      {
                        v14 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v12->vfptr,
                                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                      }
                      if ( v14 )
                      {
                        if ( v14->mIsPhoneCamera )
                          v4 = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1246
// RVA: 0x5025A0
void __fastcall UFG::TSCharacter::Mthd_is_knocked_out(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  bool v4; // al

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::IsKnockedOut(this->mpSimObj.m_pPointer);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1263
// RVA: 0x502570
void __fastcall UFG::TSCharacter::Mthd_is_killed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  bool v4; // al

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::IsKilled(this->mpSimObj.m_pPointer);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 1279
// RVA: 0x5024B0
void __fastcall UFG::TSCharacter::Mthd_is_invulnerable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax

  if ( ppResult )
  {
    if ( this->mpSimObj.m_pPointer && (v3 = this->mpHealthComp) != 0i64 && v3->m_bIsInvulnerable )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 1293
// RVA: 0x502740
void __fastcall UFG::TSCharacter::Mthd_is_moving(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rdx
  UFG::SimObject *v4; // rcx
  SSInstance **v5; // rbx
  UFG::NavComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this;
    v4 = this->mpSimObj.m_pPointer;
    v5 = ppResult;
    if ( v4 && (v4->m_Flags >> 14) & 1 )
    {
      if ( !v4 || !((v4->m_Flags >> 14) & 1) )
        v4 = 0i64;
      v6 = (UFG::NavComponent *)v4->m_Components.p[36].m_pComponent;
    }
    else
    {
      v6 = 0i64;
    }
    if ( !v3->mAIScriptInterfaceComponent.m_pSimComponent || (unsigned __int8)UFG::NavComponent::IsAtDestination(v6) )
      *v5 = (SSInstance *)SSBoolean::pool_new(0);
    else
      *v5 = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 1308
// RVA: 0x503130
void __fastcall UFG::TSCharacter::Mthd_is_script_controlled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  if ( ppResult )
  {
    v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( v3 && HIDWORD(v3[1].m_SafePointerList.mNode.mNext) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 1318
// RVA: 0x5026C0
void __fastcall UFG::TSCharacter::Mthd_is_male(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && v5->m_eGender == 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 1338
// RVA: 0x503B80
void __fastcall UFG::TSCharacter::Mthd_is_using_a_vehicle(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::CharacterOccupantComponent *v5; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent) != 0i64
      && !UFG::CharacterOccupantComponent::IsEnteringOrExiting(v5) )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 1360
// RVA: 0x503C00
void __fastcall UFG::TSCharacter::Mthd_is_using_the_vehicle(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::TSCharacter *v4; // rdi
  UFG::SimObject *v5; // rax
  bool v6; // bl
  UFG::TSVehicle *v7; // rax
  UFG::VehicleOccupantComponent *v8; // rbp
  UFG::SimObject *v9; // rdx
  UFG::CharacterOccupantComponent *v10; // rcx

  v3 = ppResult;
  v4 = this;
  if ( ppResult )
  {
    v5 = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( v5 )
    {
      if ( (v5->m_Flags >> 14) & 1 )
      {
        v7 = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
        if ( v7 )
        {
          v8 = (UFG::VehicleOccupantComponent *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(v7);
          if ( v8 )
          {
            v9 = v4->mpSimObj.m_pPointer;
            if ( v9 )
            {
              if ( (v9->m_Flags >> 14) & 1 )
              {
                v10 = (UFG::CharacterOccupantComponent *)v9->m_Components.p[44].m_pComponent;
                if ( v10 )
                {
                  v6 = 0;
                  if ( v8 == UFG::CharacterOccupantComponent::GetCurrentVehicle(v10) )
                    v6 = 1;
                }
              }
            }
          }
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 1399
// RVA: 0x508E80
void __fastcall UFG::TSCharacter::Mthd_set_non_player_damage_multiplier(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // r8

  v3 = this->mpHealthComp;
  if ( v3 )
    v3->m_NonPlayerDamageMultiplier = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1410
// RVA: 0x4FD960
void __fastcall UFG::TSCharacter::Mthd_get_non_player_damage_multiplier(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax
  float v4; // xmm0_4

  if ( ppResult )
  {
    v3 = this->mpHealthComp;
    if ( v3 )
      v4 = v3->m_NonPlayerDamageMultiplier;
    else
      v4 = *(float *)&FLOAT_1_0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1425
// RVA: 0x4FD190
void __fastcall UFG::TSCharacter::Mthd_get_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax
  float v4; // xmm0_4

  if ( ppResult )
  {
    v3 = this->mpHealthComp;
    if ( v3 )
      v4 = (float)(signed int)v3->m_fHealth;
    else
      v4 = 0.0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1440
// RVA: 0x507740
void __fastcall UFG::TSCharacter::Mthd_set_bone_visual_damage_amount(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::CharacterAnimationComponent *v5; // rdi
  SSData **v6; // r8
  SSData *v7; // rcx
  unsigned int v8; // edx
  const float *v9; // rbx
  float v10; // xmm3_4

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      if ( v3 )
      {
        if ( (v3->m_Flags >> 14) & 1 )
        {
          v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
          if ( v5 )
          {
            v6 = v4->i_data.i_array_p;
            v7 = v6[2];
            v8 = (*v6)->i_data_p->i_user_data;
            v9 = (const float *)&v6[1]->i_data_p->i_user_data;
            if ( v8 && v6[1]->i_data_p != (SSInstance *)-32i64 )
            {
              if ( v7->i_data_p == (SSInstance *)-32i64 )
                v10 = 0.0;
              else
                v10 = *(float *)&v7->i_data_p->i_user_data;
              UFG::CharacterAnimationComponent::SetVisualDamage(v5, v8, *v9, v10);
            }
            if ( *v9 < 0.0099999998 )
              UFG::CharacterAnimationComponent::ApplyCharredEffect(v5, 0.0);
          }
        }
      }
    }
  }
}

// File Line: 1474
// RVA: 0x4F67D0
void __fastcall UFG::TSCharacter::Mthd_clone_visual_damage(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rdi
  UFG::CharacterAnimationComponent *v5; // rbx
  SSInstance *v6; // rcx
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::CharacterAnimationComponent *v9; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      if ( v3 )
      {
        if ( (v3->m_Flags >> 14) & 1 )
        {
          v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
          if ( v5 )
          {
            v6 = (*v4->i_data.i_array_p)->i_data_p;
            if ( v6 )
            {
              v7 = *(UFG::SimObjectCVBase **)&v6[4].i_ref_count;
              if ( v7 )
              {
                v8 = v7->m_Flags;
                if ( (v8 >> 14) & 1 )
                {
                  v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
                }
                else if ( (v8 & 0x8000u) == 0 )
                {
                  if ( (v8 >> 13) & 1 )
                  {
                    v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
                  }
                  else if ( (v8 >> 12) & 1 )
                  {
                    v9 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v7->vfptr,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                  }
                  else
                  {
                    v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v7->vfptr,
                                                               UFG::CharacterAnimationComponent::_TypeUID);
                  }
                }
                else
                {
                  v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
                }
                if ( v9 )
                  UFG::CharacterAnimationComponent::Clone(v5, v9);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1501
// RVA: 0x509200
void __fastcall UFG::TSCharacter::Mthd_set_paint_effect(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::CharacterAnimationComponent *v5; // rax
  SSData **v6; // rdx

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    if ( v5 )
    {
      v6 = v4->i_data.i_array_p;
      UFG::CharacterAnimationComponent::ApplyPaintEffect(
        v5,
        (*v6)->i_data_p->i_user_data != 0,
        *(float *)&v6[1]->i_data_p->i_user_data,
        *(float *)&v6[2]->i_data_p->i_user_data,
        *(float *)&v6[3]->i_data_p->i_user_data);
    }
  }
}

// File Line: 1524
// RVA: 0x507990
void __fastcall UFG::TSCharacter::Mthd_set_charred_effect(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::CharacterAnimationComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    v5 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    if ( v5 )
      UFG::CharacterAnimationComponent::ApplyCharredEffect(
        v5,
        *(float *)&(*v4->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 1543
// RVA: 0x508390
void __fastcall UFG::TSCharacter::Mthd_set_footstep_override_effect(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::CharacterEffectsComponent *v4; // rbp
  SSData **v5; // rcx
  unsigned __int64 v6; // r9
  SSInstance *v7; // r14
  const char *v8; // rcx
  unsigned __int64 v9; // r8
  char *v10; // rdx
  unsigned int v11; // ebx
  unsigned int v12; // esi
  unsigned __int64 v13; // r8
  const char *v14; // rax
  unsigned __int64 v15; // rdx
  char *v16; // rdi

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v4 = (UFG::CharacterEffectsComponent *)v3->m_Components.p[38].m_pComponent;
      if ( v4 )
      {
        v5 = pScope->i_data.i_array_p;
        v6 = (*v5)->i_data_p->i_user_data;
        v7 = v5[1]->i_data_p;
        v8 = *(const char **)v6;
        v9 = *(unsigned int *)(v6 + 8) + *(_QWORD *)v6 + 1i64;
        if ( *(_QWORD *)v6 >= v9 )
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
          v12 = UFG::qStringHashUpper32(*(const char **)v6, 0xFFFFFFFF);
        }
        v13 = v7->i_user_data;
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
          v11 = UFG::qStringHashUpper32(*(const char **)v13, 0xFFFFFFFF);
        }
LABEL_16:
        UFG::CharacterEffectsComponent::SetFootstepOverride(v4, v12, v11);
      }
    }
  }
}

// File Line: 1585
// RVA: 0x5089C0
void __fastcall UFG::TSCharacter::Mthd_set_invulnerable_to_fire(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = v3->m_Components.p[38].m_pComponent;
    if ( v4 )
      LOBYTE(v4[1].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 1602
// RVA: 0x508660
void __fastcall UFG::TSCharacter::Mthd_set_health_ui_state(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = v3->m_Components.p[38].m_pComponent;
    if ( v4 )
      BYTE1(v4[1].m_SafePointerList.mNode.mNext) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 1642
// RVA: 0x5085E0
void __fastcall UFG::TSCharacter::Mthd_set_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax

  if ( this->mpHealthComp )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
        UFG::HealthComponent::SetHealth(
          this->mpHealthComp,
          (signed int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
          0i64);
    }
  }
}

// File Line: 1656
// RVA: 0x4FD530
void __fastcall UFG::TSCharacter::Mthd_get_max_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax
  float v4; // xmm0_4

  if ( ppResult )
  {
    v3 = this->mpHealthComp;
    if ( v3 )
      v4 = (float)(signed int)v3->m_fMaxHealth;
    else
      v4 = 0.0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1670
// RVA: 0x508C90
void __fastcall UFG::TSCharacter::Mthd_set_max_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rcx

  v3 = this->mpHealthComp;
  if ( v3 )
    UFG::HealthComponent::SetMaxHealth(v3, (signed int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1683
// RVA: 0x4FD640
void __fastcall UFG::TSCharacter::Mthd_get_min_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax
  float v4; // xmm0_4

  if ( ppResult )
  {
    v3 = this->mpHealthComp;
    if ( v3 )
      v4 = (float)(signed int)v3->m_fMinHealth;
    else
      v4 = FLOAT_N1_0;
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

// File Line: 1697
// RVA: 0x508CC0
void __fastcall UFG::TSCharacter::Mthd_set_min_health(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rcx

  v3 = this->mpHealthComp;
  if ( v3 )
    UFG::HealthComponent::SetMinHealth(v3, (signed int)*(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1709
// RVA: 0x4FD1E0
void __fastcall UFG::TSCharacter::Mthd_get_health_clamped_to_minimum(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rax

  if ( ppResult )
  {
    v3 = this->mpHealthComp;
    if ( v3 )
      *ppResult = (SSInstance *)SSBoolean::pool_new(v3->m_bHealthClampedToMinimum);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 1722
// RVA: 0x508630
void __fastcall UFG::TSCharacter::Mthd_set_health_clamped_to_minimum(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // r8

  v3 = this->mpHealthComp;
  if ( v3 )
    v3->m_bHealthClampedToMinimum = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 1736
// RVA: 0x50A2D0
void __fastcall UFG::TSCharacter::Mthd_set_regenerative_health_rate(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // r8

  v3 = this->mpHealthComp;
  if ( v3 )
    v3->m_fRegenerativeHealthRate = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1745
// RVA: 0x50A2F0
void __fastcall UFG::TSCharacter::Mthd_set_regenerative_health_ratio(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::HealthComponent *v3; // rcx

  v3 = this->mpHealthComp;
  if ( v3 )
    UFG::HealthComponent::SetRegenerativeHealthRatio(
      v3,
      *(const float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
      1);
}

// File Line: 1759
// RVA: 0x505EA0
void __fastcall UFG::TSCharacter::Mthd_poi_get_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  SSInstance **v4; // rdi
  UFG::SimComponent *v5; // rdx
  UFG::SimObject *v6; // rcx
  unsigned __int16 v7; // dx
  unsigned __int64 v8; // rbx
  UFG::CollectibleComponent *v9; // rax
  SSClass *v10; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
      if ( v5 )
      {
        v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + 34i64)
                                + *(_QWORD *)&v5[1].m_TypeUID
                                + 40);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = (unsigned __int64)v6->m_Components.p[25].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
              v8 = (unsigned __int64)v6->m_Components.p[10].m_pComponent;
            else
              v8 = (unsigned __int64)((v7 >> 12) & 1 ? v6->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                              v6,
                                                                                              UFG::InterestPoint::_TypeUID));
          }
          else
          {
            v8 = (unsigned __int64)v6->m_Components.p[25].m_pComponent;
          }
          if ( v8 )
          {
            v9 = UFG::CollectibleComponent::GetCollectibleComponent(*(UFG::SimObject **)(v8 + 40));
            v10 = UFG::TSCollectible::mspCollectibleClass;
            if ( !v9 )
              v10 = UFG::TSInterestPoint::mspInterestPointClass;
            *v4 = SSInstance::pool_new(v10, v8);
          }
        }
      }
    }
  }
}

// File Line: 1792
// RVA: 0x507270
void __fastcall UFG::TSCharacter::Mthd_set_attracted_to_pois(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    v5 = v3->m_Components.p[43].m_pComponent;
    if ( v5 )
      LOBYTE(v5[1].m_SafePointerList.mNode.mNext) ^= (LOBYTE(v5[1].m_SafePointerList.mNode.mNext) ^ ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
  }
}

// File Line: 1813
// RVA: 0x505FF0
void __fastcall UFG::TSCharacter::Mthd_poi_use(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // rdi
  UFG::TSCharacter *v4; // rsi
  SSInstance *v5; // rax
  SSClass *v6; // r8
  UFG::InterestPoint *v7; // rbx
  UFG::ePOIUseType v8; // er10
  UFG::SimObject *v9; // rdx
  UFG::InterestPointUserComponent *v10; // rcx
  UFG::qStaticSymbol *v11; // r9

  v3 = pScope;
  v4 = this;
  v5 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( !v5 )
    goto LABEL_6;
  v6 = v5->i_class_p;
  if ( v6 != SSBrain::c_symbol_class_p )
  {
    if ( v6 == UFG::TSInterestPoint::mspInterestPointClass )
    {
      v7 = (UFG::InterestPoint *)v5->i_user_data;
      goto LABEL_7;
    }
LABEL_6:
    v7 = 0i64;
    goto LABEL_7;
  }
  v7 = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&v5->i_user_data);
LABEL_7:
  v8 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                       &UFG::gPOIUseTypeEnum,
                       (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
  if ( v7 )
  {
    v9 = v4->mpSimObj.m_pPointer;
    if ( v9 )
    {
      if ( (v9->m_Flags >> 14) & 1 )
      {
        if ( v9 )
        {
          if ( (v9->m_Flags >> 14) & 1 )
          {
            v10 = (UFG::InterestPointUserComponent *)v9->m_Components.p[43].m_pComponent;
            if ( v10 )
            {
              v11 = &qSymbol_ScriptSkip;
              if ( !*(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64) )
                v11 = (UFG::qStaticSymbol *)&UFG::gNullQSymbol;
              UFG::InterestPointUserComponent::UsePOI(v10, v7, v8, (UFG::qSymbol *)&v11->mUID);
            }
          }
        }
      }
    }
  }
}

// File Line: 1840
// RVA: 0x505FB0
void __fastcall UFG::TSCharacter::Mthd_poi_stop_using_use(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
      JUMPOUT(v3->m_Components.p[43].m_pComponent, 0i64, UFG::InterestPointUserComponent::StopPOI);
  }
}

// File Line: 1860
// RVA: 0x4DCB10
bool __fastcall UFG::TSCharacter::Coro_poi_stop_using(UFG::TSCharacter *this, SSInvokedCoroutine *pScope, __int64 a3, __int64 a4)
{
  UFG::SimObject *v4; // r8
  UFG::TSCharacter *v5; // rbx
  UFG::InterestPointUserComponent *v6; // rsi
  SSInstance *v7; // rax
  SSClass *v8; // rcx
  UFG::InterestPoint *v9; // rax
  UFG::InterestPoint *v10; // rax
  ActionNode *v11; // rcx
  ActionNode *v12; // rdx
  UFG::SimObject *v13; // rcx
  UFG::SimComponent *v14; // rcx

  v4 = this->mpSimObj.m_pPointer;
  v5 = this;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count )
    {
LABEL_18:
      v12 = v5->mRootPOINode;
      if ( v12 )
      {
        v13 = v5->mpSimObj.m_pPointer;
        if ( v13 )
        {
          if ( (v13->m_Flags >> 14) & 1 )
          {
            v14 = v13->m_Components.p[7].m_pComponent;
            if ( v14 )
              return ActionController::IsPlaying((ActionController *)&v14[3], v12) == 0;
          }
        }
      }
      return 1;
    }
    this->mRootPOINode = 0i64;
    if ( !v4 )
      return 1;
    if ( !((v4->m_Flags >> 14) & 1) )
      return 1;
    v6 = (UFG::InterestPointUserComponent *)v4->m_Components.p[43].m_pComponent;
    if ( !v6 )
      return 1;
    v7 = (*pScope->i_data.i_array_p)->i_data_p;
    if ( !v7 )
      goto LABEL_10;
    v8 = v7->i_class_p;
    if ( v8 == SSBrain::c_symbol_class_p )
    {
      v9 = UFG::InterestPoint::GetNamed((UFG::qSymbol *)&v7->i_user_data);
      if ( !v9 )
        goto LABEL_10;
    }
    else
    {
      if ( v8 != UFG::TSInterestPoint::mspInterestPointClass )
        goto LABEL_10;
      v9 = (UFG::InterestPoint *)v7->i_user_data;
    }
    if ( v9 )
    {
      v11 = v9->mInterestPointType->mBehaviour;
LABEL_17:
      v5->mRootPOINode = v11;
      UFG::InterestPointUserComponent::StopPOI(v6, (__int64)pScope, (__int64)v4, a4);
      goto LABEL_18;
    }
LABEL_10:
    v10 = v6->mActiveInterestPoint.mInterestPoint.m_pPointer;
    if ( v10 )
      v11 = v10->mInterestPointType->mBehaviour;
    else
      v11 = 0i64;
    goto LABEL_17;
  }
  return 1;
}

// File Line: 1923
// RVA: 0x507AA0
void __fastcall UFG::TSCharacter::Mthd_set_collision_avoidance_type(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v4; // rax
  __int64 v5; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v7; // rax
  UFG::AIScriptInterfaceComponent *v8; // rcx
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v3 = this;
  if ( this->mActiveAIEntityComponent.m_pSimComponent && (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.m_EnumSymbol = result;
    *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
    pTrackEnumBinding.m_uEnumUID = 0;
    if ( collisionAvoidanceEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&collisionAvoidanceEnum, &pTrackEnumBinding);
    }
    else
    {
      v4 = collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v4;
      pTrackEnumBinding.mNext = &collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode;
      collisionAvoidanceEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v5 = pTrackEnumBinding.m_EnumValue;
    v6 = pTrackEnumBinding.mPrev;
    v7 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v7->mPrev = v6;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    if ( (unsigned int)v5 < 9 )
    {
      v8 = (UFG::AIScriptInterfaceComponent *)v3->mAIScriptInterfaceComponent.m_pSimComponent;
      if ( v8 )
        UFG::AIScriptInterfaceComponent::SetCollisionAvoidanceOverride(v8, v5);
    }
  }
}

// File Line: 1951
// RVA: 0x506890
void __fastcall UFG::TSCharacter::Mthd_reset_collision_avoidance_type(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
    JUMPOUT(
      this->mAIScriptInterfaceComponent.m_pSimComponent,
      0i64,
      UFG::AIScriptInterfaceComponent::ClearCollisionAvoidanceOverride);
}

// File Line: 1967
// RVA: 0x4FD9B0
void __fastcall UFG::TSCharacter::Mthd_get_objective(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  const char *v4; // rdi
  signed __int64 v5; // rbx
  unsigned int v6; // eax
  AStringRef *v7; // rbx
  bool v8; // zf
  AObjReusePool<AStringRef> *v9; // rax
  AObjBlock<AStringRef> *v10; // rcx
  unsigned __int64 v11; // rdx
  bool v12; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v13; // rcx
  AString str; // [rsp+50h] [rbp+8h]

  v3 = ppResult;
  if ( this->mActiveAIEntityComponent.m_pSimComponent )
  {
    if ( ppResult )
    {
      v4 = UFG::AIObjectiveNames[SHIDWORD(this->mActiveAIEntityComponent.m_pSimComponent[65].vfptr)];
      v5 = -1i64;
      do
        ++v5;
      while ( v4[v5] );
      v6 = AMemory::c_req_byte_size_func(v5 + 1);
      str.i_str_ref_p = AStringRef::pool_new(v4, v5, v6, 1u, 0, 1);
      *v3 = SSString::as_instance(&str);
      v7 = str.i_str_ref_p;
      v8 = str.i_str_ref_p->i_ref_count == 1;
      --v7->i_ref_count;
      if ( v8 )
      {
        if ( v7->i_deallocate )
          AMemory::c_free_func(v7->i_cstr_p);
        v9 = AStringRef::get_pool();
        v10 = v9->i_block_p;
        v11 = (unsigned __int64)v10->i_objects_a;
        if ( (unsigned __int64)v7 < v11
          || (v12 = (unsigned __int64)v7 < v11 + 24i64 * v10->i_size, v13 = &v9->i_pool, !v12) )
        {
          v13 = &v9->i_exp_pool;
        }
        APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v13, v7);
      }
    }
  }
}

// File Line: 1985
// RVA: 0x508EA0
void __fastcall UFG::TSCharacter::Mthd_set_objective(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rbp
  const char ***v5; // rsi
  const char **v6; // rdi
  UFG::eAIObjective v7; // ebx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (const char ***)&(*v3)->i_data_p->i_user_data;
  if ( this->mActiveAIEntityComponent.m_pSimComponent && (*v3)->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = UFG::AIObjectiveNames;
    v7 = 0;
    while ( (unsigned int)UFG::qStringCompareInsensitive(**v5, *v6, -1) )
    {
      ++v7;
      ++v6;
      if ( (unsigned int)v7 >= 0x24 )
        return;
    }
    UFG::ActiveAIEntityComponent::SetCurrentObjective(
      (UFG::ActiveAIEntityComponent *)v4->mActiveAIEntityComponent.m_pSimComponent,
      v7,
      "TSCharacter::Mthd_set_objective");
  }
}

// File Line: 2007
// RVA: 0x508F30
void __fastcall UFG::TSCharacter::Mthd_set_objective_and_actor(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::eAIObjective v4; // ebx
  UFG::TSCharacter *v5; // rbp
  SSActor *v6; // rsi
  const char ***v7; // r14
  SSClass *v8; // rdi
  UFG::SimObject *v9; // rcx
  UFG::TargetingSystemBaseComponent *v10; // r15
  const char **v11; // rdi

  v3 = pScope->i_data.i_array_p;
  v4 = 0;
  v5 = this;
  v6 = (SSActor *)v3[1]->i_data_p;
  v7 = (const char ***)&(*v3)->i_data_p->i_user_data;
  if ( !v6 )
    goto LABEL_6;
  v8 = v6->i_class_p;
  if ( !v8->vfptr->is_actor_class((SSClassDescBase *)&v8->vfptr) )
  {
    if ( v8 == SSBrain::c_symbol_class_p && LODWORD(v6->i_user_data) != -1 )
    {
      v6 = SSActor::find((ASymbol *)&v6->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v6 = 0i64;
  }
LABEL_7:
  if ( v5->mActiveAIEntityComponent.m_pSimComponent )
  {
    if ( v7 )
    {
      if ( v6 )
      {
        v9 = v5->mpSimObj.m_pPointer;
        if ( v9 )
        {
          if ( (v9->m_Flags >> 14) & 1 )
          {
            v10 = (UFG::TargetingSystemBaseComponent *)v9->m_Components.p[20].m_pComponent;
            if ( v10 )
            {
              v11 = UFG::AIObjectiveNames;
              while ( (unsigned int)UFG::qStringCompareInsensitive(**v7, *v11, -1) )
              {
                ++v4;
                ++v11;
                if ( (unsigned int)v4 >= 0x24 )
                  return;
              }
              UFG::ActiveAIEntityComponent::SetCurrentObjective(
                (UFG::ActiveAIEntityComponent *)v5->mActiveAIEntityComponent.m_pSimComponent,
                v4,
                "TSCharacter::Mthd_set_objective_and_actor");
              UFG::TargetingSystemBaseComponent::SetTarget(
                v10,
                eTARGET_TYPE_AI_OBJECTIVE,
                *(UFG::SimObject **)&v6[1].i_icoroutines_to_update.i_count);
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
  UFG::TSCharacter *v2; // rdi
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v3; // rax
  unsigned int v4; // er8
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v5; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v2 = this;
  if ( !this->mActiveAIEntityComponent.m_pSimComponent || (*pScope->i_data.i_array_p)->i_data_p == (SSInstance *)-32i64 )
    return 1;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( geAIObjectiveEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&geAIObjectiveEnum, &pTrackEnumBinding);
  }
  else
  {
    v3 = geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v3;
    pTrackEnumBinding.mNext = &geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode;
    geAIObjectiveEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v4 = pTrackEnumBinding.m_EnumValue;
  v5 = pTrackEnumBinding.mPrev;
  v6 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v6->mPrev = v5;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  return HIDWORD(v2->mActiveAIEntityComponent.m_pSimComponent[65].vfptr) != v4;
}

// File Line: 2060
// RVA: 0x4F6560
void __fastcall UFG::TSCharacter::Mthd_clear_objective(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *v3; // rcx

  v3 = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    UFG::ActiveAIEntityComponent::SetCurrentObjective(v3, 0, "TSCharacter::Mthd_clear_objective()");
}

// File Line: 2073
// RVA: 0x506DD0
void __fastcall UFG::TSCharacter::Mthd_set_AI_behaviour(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *v3; // rcx

  v3 = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    UFG::ActiveAIEntityComponent::SetBehaviourTree(
      v3,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2089
// RVA: 0x508C50
void __fastcall UFG::TSCharacter::Mthd_set_max_engagement_distance(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::SimComponent *v4; // rdx
  int v5; // eax

  v3 = pScope->i_data.i_array_p;
  v4 = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v4 )
  {
    v5 = (*v3)->i_data_p->i_user_data;
    HIDWORD(v4[64].m_BoundComponentHandles.mNode.mPrev) = v3[1]->i_data_p->i_user_data;
    LODWORD(v4[64].m_BoundComponentHandles.mNode.mPrev) = v5;
  }
}

// File Line: 2105
// RVA: 0x4F9390
void __fastcall UFG::TSCharacter::Mthd_engage_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *v3; // rax

  v3 = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    v3->m_EngagementOverrideEnabled = 1;
}

// File Line: 2118
// RVA: 0x506A50
void __fastcall UFG::TSCharacter::Mthd_return_to_default_engagement_of_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[64].m_BoundComponentHandles.mNode.mNext) = 0;
}

// File Line: 2131
// RVA: 0x50B380
void __fastcall UFG::TSCharacter::Mthd_set_xform_to_defend(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r11
  UFG::SimObject *v4; // rdx

  v3 = pScope->i_data.i_array_p;
  v4 = *(UFG::SimObject **)((*v3)->i_data_p->i_user_data + 104);
  if ( v4 )
    v4 = (UFG::SimObject *)v4->mNode.mParent;
  UFG::TSCharacter::SetPositionToDefend(
    this,
    v4,
    *(float *)&v3[1]->i_data_p->i_user_data,
    (UFG::qSymbol *)&v3[2]->i_data_p->i_user_data,
    (UFG::qSymbol *)&v3[3]->i_data_p->i_user_data,
    (UFG::qSymbol *)&v3[4]->i_data_p->i_user_data);
}

// File Line: 2150
// RVA: 0x50FCA0
void __fastcall UFG::TSCharacter::SetPositionToDefend(UFG::TSCharacter *this, UFG::SimObject *object_to_defend, float radius, UFG::qSymbol *crouchedOrStandingSymbol, UFG::qSymbol *abandonPositionWhenCompromisedSymbol, UFG::qSymbol *abandonPositionWhenNoGunSymbol)
{
  UFG::TSCharacter *v6; // r10
  bool v7; // r8
  bool abandon_when_compromised; // cl
  bool abandon_when_no_gun; // al
  UFG::AIScriptInterfaceComponent *v10; // r10

  v6 = this;
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
  v10 = (UFG::AIScriptInterfaceComponent *)v6->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v10 )
    UFG::AIScriptInterfaceComponent::SetPositionToDefend(
      v10,
      object_to_defend,
      radius,
      v7,
      abandon_when_compromised,
      abandon_when_no_gun);
}

// File Line: 2211
// RVA: 0x4F6610
void __fastcall UFG::TSCharacter::Mthd_clear_pos_to_defend(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(
    this->mAIScriptInterfaceComponent.m_pSimComponent,
    0i64,
    UFG::AIScriptInterfaceComponent::ClearPositionToDefend);
}

// File Line: 2224
// RVA: 0x4F64A0
void __fastcall UFG::TSCharacter::Mthd_clear_current_emotion(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    LODWORD(v3[10].m_BoundComponentHandles.mNode.mNext) = 0;
}

// File Line: 2237
// RVA: 0x507C50
void __fastcall UFG::TSCharacter::Mthd_set_current_emotion(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rbp
  const char ***v5; // rsi
  int v6; // edi
  const char **v7; // rbx
  UFG::SimComponent *v8; // rax

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (const char ***)&(*v3)->i_data_p->i_user_data;
  if ( (*v3)->i_data_p != (SSInstance *)-32i64 )
  {
    v6 = 0;
    v7 = UFG::AIEmotionNames;
    while ( (unsigned int)UFG::qStringCompareInsensitive(*v7, **v5, -1) )
    {
      ++v7;
      ++v6;
      if ( (signed __int64)v7 >= (signed __int64)&UFG::InterestPointUserComponent::_TypeName )
        return;
    }
    v8 = v4->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( v8 )
      LODWORD(v8[10].m_BoundComponentHandles.mNode.mNext) = v6;
  }
}

// File Line: 2278
// RVA: 0x4F5FC0
void __fastcall UFG::TSCharacter::Mthd_begin_fleeing(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[32].m_BoundComponentHandles.mNode.mPrev) |= 0x10u;
}

// File Line: 2291
// RVA: 0x50C310
void __fastcall UFG::TSCharacter::Mthd_stop_fleeing(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[32].m_BoundComponentHandles.mNode.mPrev) &= 0xEFu;
}

// File Line: 2304
// RVA: 0x4F43D0
void __fastcall UFG::TSCharacter::Mthd_add_supplementary_attack_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::ActiveAIEntityComponent *v7; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( !v5 )
    goto LABEL_12;
  v6 = v5->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
         v6,
         *v3,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_12:
    v5 = 0i64;
LABEL_7:
  v7 = (UFG::ActiveAIEntityComponent *)v4->mActiveAIEntityComponent.m_pSimComponent;
  if ( v7 )
  {
    if ( v5 )
      UFG::ActiveAIEntityComponent::AddSupplementaryAttackTarget(
        v7,
        *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count);
  }
}

// File Line: 2319
// RVA: 0x506740
void __fastcall UFG::TSCharacter::Mthd_remove_supplementary_attack_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::ActiveAIEntityComponent *v7; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( !v5 )
    goto LABEL_12;
  v6 = v5->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
         v6,
         *v3,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_12:
    v5 = 0i64;
LABEL_7:
  v7 = (UFG::ActiveAIEntityComponent *)v4->mActiveAIEntityComponent.m_pSimComponent;
  if ( v7 )
  {
    if ( v5 )
      UFG::ActiveAIEntityComponent::RemoveSupplementaryAttackTarget(
        v7,
        *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count);
  }
}

// File Line: 2334
// RVA: 0x4F4340
void __fastcall UFG::TSCharacter::Mthd_add_scary_actor(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::AIEntityComponent *v7; // rcx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( !v5 )
    goto LABEL_12;
  v6 = v5->i_class_p;
  if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
         v6,
         *v3,
         ppResult) )
  {
    goto LABEL_7;
  }
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_12:
    v5 = 0i64;
LABEL_7:
  v7 = (UFG::AIEntityComponent *)v4->mActiveAIEntityComponent.m_pSimComponent;
  if ( v7 )
  {
    if ( v5 )
      UFG::AIEntityComponent::AddThreatTarget(v7, *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count, 100.0);
  }
}

// File Line: 2349
// RVA: 0x4F6630
void __fastcall UFG::TSCharacter::Mthd_clear_scary_actors(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(this->mActiveAIEntityComponent.m_pSimComponent, 0i64, UFG::AIEntityComponent::ClearThreatTargets);
}

// File Line: 2362
// RVA: 0x50C040
void __fastcall UFG::TSCharacter::Mthd_start_holding_action_request(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *v3; // rcx

  v3 = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    UFG::AIScriptInterfaceComponent::StartHoldingActionRequest(
      v3,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2377
// RVA: 0x50C330
void __fastcall UFG::TSCharacter::Mthd_stop_holding_action_request(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *v3; // rcx

  v3 = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    UFG::AIScriptInterfaceComponent::StopHoldingActionRequest(
      v3,
      *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 2392
// RVA: 0x50C360
void __fastcall UFG::TSCharacter::Mthd_stop_holding_all_action_requests(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  JUMPOUT(
    this->mAIScriptInterfaceComponent.m_pSimComponent,
    0i64,
    UFG::AIScriptInterfaceComponent::StopHoldingAllActionRequests);
}

// File Line: 2400
// RVA: 0x50A1E0
void __fastcall UFG::TSCharacter::Mthd_set_race(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rbx
  UFG::RaceTrail *v4; // rax
  UFG::SimObject *v5; // r8
  UFG::RaceTrail *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::RoadSpaceComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx

  v3 = this;
  v4 = UFG::RaceManager::GetRaceTrail((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v5 = v3->mpSimObj.m_pPointer;
  v6 = v4;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::RoadSpaceComponent *)v5->m_Components.p[24].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      v9 = (UFG::SimObjectGame *)v3->mpSimObj.m_pPointer;
      if ( (v7 >> 13) & 1 )
      {
        v8 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v8 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v8 = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v9->vfptr,
                                          UFG::RoadSpaceComponent::_TypeUID);
      }
    }
    else
    {
      v8 = (UFG::RoadSpaceComponent *)v5->m_Components.p[24].m_pComponent;
    }
    if ( v8 )
      UFG::RoadSpaceComponent::SetRaceTrail(v8, v6);
  }
}

// File Line: 2413
// RVA: 0x4FE830
void __fastcall UFG::TSCharacter::Mthd_get_race_index(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // r9
  unsigned int v4; // ebx
  SSInstance **v5; // rdi
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::RacePosition *v8; // rcx

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = -1;
  v5 = ppResult;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v3->m_Components.p[24].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
    }
    else
    {
      v7 = v3->m_Components.p[24].m_pComponent;
    }
    if ( v7 )
    {
      v8 = (UFG::RacePosition *)v7[26].m_SafePointerList.mNode.mPrev;
      if ( v8 )
        v4 = UFG::RacePosition::GetRaceIndex(v8);
    }
  }
  *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 2430
// RVA: 0x4F9DB0
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rdi
  SSInvokedMethod *v4; // r14
  int v5; // ebp
  SSActor *v6; // rbx
  SSClass *v7; // rsi
  UFG::SimObjectVehicle *v8; // rbx
  SSData **v9; // rdx
  UFG::BaseCameraComponent *v10; // rax

  v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( !v3 || !((v3->m_Flags >> 14) & 1) )
    return;
  v5 = 0;
  v6 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v6 )
    goto LABEL_10;
  v7 = v6->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))v7->vfptr->is_actor_class)(
          v7,
          pScope,
          ppResult) )
  {
    if ( v7 != SSBrain::c_symbol_class_p || LODWORD(v6->i_user_data) == -1 )
      goto LABEL_10;
    v6 = SSActor::find((ASymbol *)&v6->i_user_data);
  }
  if ( !v6 )
  {
LABEL_10:
    v8 = 0i64;
    goto LABEL_11;
  }
  v8 = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)v6);
LABEL_11:
  UFG::VehicleUtility::ExitVehicleNoAnim((UFG::SimObject *)&v3->vfptr);
  v9 = v4->i_data.i_array_p;
  LOBYTE(v5) = v9[1]->i_data_p->i_user_data == 0;
  UFG::VehicleUtility::PlaceCharacterInVehicle(
    v3,
    v8,
    (UFG::eTargetTypeEnum)(v5 + 4),
    v9[2]->i_data_p->i_user_data != 0,
    0,
    1);
  if ( v8 )
    UFG::SimObjectVehicle::GetComponent<UFG::VehicleAudioComponent>(v8);
  if ( UFG::GetLocalPlayer() == v3 && v8 )
  {
    v10 = UFG::GetCurrentBaseCamera();
    if ( v10 )
      ((void (__fastcall *)(UFG::BaseCameraComponent *))v10->vfptr[14].__vecDelDtor)(v10);
    if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)&v8->vfptr) )
    {
      if ( UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle((UFG::SimObject *)&v8->vfptr) )
        UFG::UI::PauseGame("WorldMap");
    }
  }
}

// File Line: 2499
// RVA: 0x4F9F00
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle_seat(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v3; // r14
  UFG::SimObjectCharacter *v4; // rdi
  SSActor *v5; // rbx
  SSClass *v6; // rsi
  UFG::SimObjectVehicle *v7; // rbx
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  UFG::BaseCameraComponent *v12; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v14; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v16; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h]
  UFG::qSymbol result; // [rsp+80h] [rbp+20h]

  v3 = pScope;
  v4 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !v4 || !((v4->m_Flags >> 14) & 1) )
    return;
  v5 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v5 )
    goto LABEL_10;
  v6 = v5->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))v6->vfptr->is_actor_class)(
          v5->i_class_p,
          pScope,
          ppResult) )
  {
    if ( v6 != SSBrain::c_symbol_class_p || LODWORD(v5->i_user_data) == -1 )
      goto LABEL_10;
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  }
  if ( !v5 )
  {
LABEL_10:
    v7 = 0i64;
    goto LABEL_11;
  }
  v7 = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)v5);
LABEL_11:
  UFG::VehicleUtility::ExitVehicleNoAnim((UFG::SimObject *)&v4->vfptr);
  v8 = UFG::qSymbol::create_from_string(
         &result,
         **(const char ***)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
    v9 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v9;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  if ( (signed int)pTrackEnumBinding.m_EnumValue < 91 )
  {
    UFG::VehicleUtility::PlaceCharacterInVehicle(
      v4,
      v7,
      (UFG::eTargetTypeEnum)pTrackEnumBinding.m_EnumValue,
      *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 2) + 8i64) + 32i64) != 0i64,
      0,
      0);
    if ( UFG::GetLocalPlayer() == v4 && v7 )
    {
      v12 = UFG::GetCurrentBaseCamera();
      if ( v12 )
        ((void (__fastcall *)(UFG::BaseCameraComponent *))v12->vfptr[14].__vecDelDtor)(v12);
    }
    v13 = pTrackEnumBinding.mPrev;
    v14 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v14->mPrev = v13;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  else
  {
    v10 = pTrackEnumBinding.mPrev;
    v11 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v11->mPrev = v10;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v15 = pTrackEnumBinding.mPrev;
  v16 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v16->mPrev = v15;
}

// File Line: 2551
// RVA: 0x4FA0F0
void __fastcall UFG::TSCharacter::Mthd_force_enter_vehicle_trunk(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rdi
  UFG::SimObjectVehicle *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // r14
  UFG::BaseCameraComponent *v7; // rax

  v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  if ( !v3 || !((v3->m_Flags >> 14) & 1) )
    return;
  v4 = 0i64;
  v5 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( v5 )
  {
    v6 = v5->i_class_p;
    if ( ((unsigned __int8 (__fastcall *)(SSClass *, SSInvokedMethod *, SSInstance **))v6->vfptr->is_actor_class)(
           v6,
           pScope,
           ppResult) )
    {
      goto LABEL_8;
    }
    if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    {
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
LABEL_8:
      if ( v5 )
        v4 = UFG::TSVehicle::GetSafeSimObjectVehicle((UFG::TSVehicle *)v5);
      goto LABEL_11;
    }
  }
  v5 = 0i64;
LABEL_11:
  UFG::VehicleUtility::PlaceCharacterInTrunk((UFG::SimObject *)&v3->vfptr, v4);
  if ( UFG::GetLocalPlayer() == v3 && v5 )
  {
    v7 = UFG::GetCurrentBaseCamera();
    if ( v7 )
      ((void (__fastcall *)(UFG::BaseCameraComponent *))v7->vfptr[14].__vecDelDtor)(v7);
  }
}

// File Line: 2575
// RVA: 0x4F8B80
void __fastcall UFG::TSCharacter::Mthd_enable_in_car_reactions(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // bl
  UFG::SimComponent *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v3, UFG::ActorAudioComponent::_TypeUID);
    if ( v5 )
    {
      LOBYTE(v5[8].m_pSimObject) &= 0xEFu;
      LOBYTE(v5[8].m_pSimObject) |= 16 * v4;
    }
  }
}

// File Line: 2588
// RVA: 0x508BB0
void __fastcall UFG::TSCharacter::Mthd_set_is_tired(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  bool v4; // bl
  unsigned __int16 v5; // dx
  UFG::SimObjectCharacterPropertiesComponent *v6; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             (UFG::SimObjectGame *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v3->vfptr,
                                                             UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
    }
    if ( v6 )
      v6->mIsTired = v4;
  }
}

// File Line: 2603
// RVA: 0x504E80
void __fastcall UFG::TSCharacter::Mthd_move_stop(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rbx
  SSInvokedCoroutine *v4; // rcx

  v3 = this;
  UFG::TSCharacter::ClearTarget(this);
  v4 = v3->mpNavigationThread.i_obj_p;
  if ( v4 && v3->mpNavigationThread.i_ptr_id == v4->i_ptr_id )
    ++v4->i_pending_count;
  v3->mpNavigationThread.i_obj_p = 0i64;
  v3->mpNavigationThread.i_ptr_id = 0;
}

// File Line: 2614
// RVA: 0x4FA1D0
void __fastcall UFG::TSCharacter::Mthd_force_update_targeting(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  UFG::TargetingSystemPedBaseComponent *v4; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v3);
    if ( v4 )
      v4->m_bForceUpdate = 1;
  }
}

// File Line: 2650
// RVA: 0x4FD580
void __fastcall UFG::TSCharacter::Mthd_get_melee_weapon(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::qSymbol *v5; // rdx
  unsigned int v6; // eax
  UFG::SimComponent *v7; // r8
  UFG::SimObject *v8; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v6 = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, v5);
    if ( v3
      && (v7 = v3->m_Components.p[20].m_pComponent) != 0i64
      && (v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + v6 + 8i64)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40)) != 0i64 )
    {
      if ( UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID) )
      {
        *v4 = SSBrain::c_nil_p;
        return;
      }
    }
    else
    {
      v8 = 0i64;
    }
    *v4 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v8);
  }
}

// File Line: 2670
// RVA: 0x4FCE10
void __fastcall UFG::TSCharacter::Mthd_get_firearm(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::qSymbol *v5; // rdx
  unsigned int v6; // eax
  UFG::SimComponent *v7; // r8
  UFG::SimObject *v8; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v6 = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gTargetTypeEnum, v5);
    if ( v3
      && (v7 = v3->m_Components.p[20].m_pComponent) != 0i64
      && (v8 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + v6 + 8i64)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40)) != 0i64
      && UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID) )
    {
      *v4 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v8);
    }
    else
    {
      *v4 = SSBrain::c_nil_p;
    }
  }
}

// File Line: 2692
// RVA: 0x4FCED0
void __fastcall UFG::TSCharacter::Mthd_get_firearm_type(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimComponent *v5; // rdi
  UFG::SimObjectProp *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimObjectWeaponPropertiesComponent *v8; // rax
  UFG::FireModeInfo *v9; // rcx
  EnumList<unsigned long> *v10; // rax
  ASymbol *v11; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = v3->m_Components.p[20].m_pComponent) != 0i64
      && (v6 = *(UFG::SimObjectProp **)(56i64
                                      * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags
                                                           + (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                                                                             &UFG::gTargetTypeEnum,
                                                                             (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data)
                                                           + 8i64)
                                      + *(_QWORD *)&v5[1].m_TypeUID
                                      + 40)) != 0i64
      && ((v7 = v6->m_Flags, !((v7 >> 14) & 1)) ? ((v7 & 0x8000u) == 0 ? (!((v7 >> 13) & 1) ? (!((v7 >> 12) & 1) ? (v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) : (v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v8 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v6))) : (v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v8 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v6->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)),
          v8) )
    {
      v9 = v8->mWeaponTypeInfo->mFireModes[v8->mFireMode];
      if ( (signed int)UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.size <= 0 )
        v10 = 0i64;
      else
        v10 = *UFG::gSimObjectWeaponTypeTrackEnum.m_enumLists.p;
      v11 = (ASymbol *)UFG::qSymbol::create_from_string(&result, v10->m_enumName.p[v9->mSimObjectWeaponType]);
    }
    else
    {
      v11 = ASymbol::get_null();
    }
    *v4 = SSSymbol::as_instance(v11);
  }
}

// File Line: 2726
// RVA: 0x4F8450
void __fastcall UFG::TSCharacter::Mthd_disable_hostile(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *v3; // rax

  v3 = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    v3->m_HostilityEnabled = 0;
}

// File Line: 2736
// RVA: 0x4F8B60
void __fastcall UFG::TSCharacter::Mthd_enable_hostile(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    HIBYTE(v3[14].m_Flags) = 1;
}

// File Line: 2750
// RVA: 0x5063A0
void __fastcall UFG::TSCharacter::Mthd_reinitialize(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
      UFG::SimObjectUtility::ReinitializeSimObject(v3, 1, 0);
  }
}

// File Line: 2766
// RVA: 0x506910
void __fastcall UFG::TSCharacter::Mthd_reset_state(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
      UFG::SimObjectUtility::ResetState(v3, 0, 0);
  }
}

// File Line: 2782
// RVA: 0x506940
void __fastcall UFG::TSCharacter::Mthd_reset_state_keep_items(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
      UFG::SimObjectUtility::ResetState(v3, 1, 0);
  }
}

// File Line: 2793
// RVA: 0x5117B0
bool __fastcall UFG::TSCharacter::_is_grappling_actor(UFG::TSCharacter *this, UFG::SimObject *pGrappler, UFG::SimObject *pTarget)
{
  UFG::SimObject *v3; // rbx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v3 = pTarget;
  result = 0;
  if ( pGrappler )
  {
    v4 = UFG::SimObject::GetComponentOfType(pGrappler, UFG::TargetingSystemPedBaseComponent::_TypeUID);
    if ( v4 )
    {
      if ( v3 == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 31i64)
                                    + *(_QWORD *)&v4[1].m_TypeUID
                                    + 40) )
        result = 1;
    }
  }
  return result;
}

// File Line: 2817
// RVA: 0x501690
void __fastcall UFG::TSCharacter::Mthd_is_grappling_actor(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObject *v4; // rbx
  bool v5; // cl
  UFG::SimObject *v6; // rsi
  UFG::SimComponent *v7; // rax

  v3 = ppResult;
  if ( ppResult )
  {
    v4 = this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( v4 && (v4->m_Flags >> 14) & 1 )
    {
      v6 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0)->mpSimObj.m_pPointer;
      v7 = UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemPedBaseComponent::_TypeUID);
      v5 = v7
        && v6 == *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 31i64)
                                    + *(_QWORD *)&v7[1].m_TypeUID
                                    + 40);
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 2843
// RVA: 0x500710
void __fastcall UFG::TSCharacter::Mthd_is_a_driver(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::SimObject *v4; // rdx
  UFG::SimComponentHolder *v5; // rax
  UFG::SimComponent *v6; // rdx

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = this->mpSimObj.m_pPointer;
    if ( v4
      && (v4->m_Flags >> 14) & 1
      && (v5 = v4->m_Components.p, (v6 = v5[44].m_pComponent) != 0i64)
      && LODWORD(v6[1].m_SafePointerList.mNode.mNext) == 4
      && !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v5[44].m_pComponent) )
    {
      *v3 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v3 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 2869
// RVA: 0x503850
void __fastcall UFG::TSCharacter::Mthd_is_the_driver(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::SimObject *v4; // rbx
  bool v5; // di
  UFG::TSVehicle *v6; // rax
  UFG::VehicleOccupantComponent *v7; // rax
  UFG::SimComponentHolder *v8; // rcx
  UFG::SimComponent *v9; // rbx

  v3 = ppResult;
  if ( ppResult )
  {
    v4 = this->mpSimObj.m_pPointer;
    v5 = 0;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 )
      {
        v6 = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
        if ( v6 )
        {
          v7 = (UFG::VehicleOccupantComponent *)Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(v6);
          v8 = v4->m_Components.p;
          v9 = v8[44].m_pComponent;
          if ( v9 )
          {
            if ( v7 == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)v8[44].m_pComponent)
              && LODWORD(v9[1].m_SafePointerList.mNode.mNext) == 4 )
            {
              v5 = 0;
              if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v9) )
                v5 = 1;
            }
          }
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 2911
// RVA: 0x501BE0
void __fastcall UFG::TSCharacter::Mthd_is_in_trunk(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rdi
  UFG::SimObjectCVBase *v4; // rcx
  bool v5; // bl
  SSInstance **v6; // rsi
  UFG::TargetingSystemPedBaseComponent *v7; // rax
  UFG::SimObject *v8; // r8
  UFG::SimObject *v9; // rcx

  if ( ppResult )
  {
    v3 = this;
    v4 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v5 = 0;
    v6 = ppResult;
    if ( v4 && (v4->m_Flags >> 14) & 1 && v4 && (v4->m_Flags >> 14) & 1 )
    {
      if ( !v4 || !((v4->m_Flags >> 14) & 1) )
        v4 = 0i64;
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedBaseComponent>(v4);
      if ( v7 )
      {
        v8 = v7->m_pTargets[(unsigned __int8)v7->m_pTargetingMap->m_Map.p[13]].m_pTarget.m_pPointer;
        if ( v8 )
        {
          v9 = v3->mpSimObj.m_pPointer;
          if ( !v9 || !((v9->m_Flags >> 14) & 1) )
            v9 = 0i64;
          v5 = 0;
          if ( v9 == v8 )
            v5 = 1;
        }
      }
    }
    *v6 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 2943
// RVA: 0x501B20
void __fastcall UFG::TSCharacter::Mthd_is_in_the_trunk(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::TSCharacter *v4; // rdi
  UFG::SimObject *v5; // rax
  bool v6; // bl
  UFG::TSVehicle *v7; // rax
  UFG::SimObjectVehicle *v8; // rax
  UFG::TargetingSystemVehicleComponent *v9; // rax
  UFG::SimObject *v10; // rcx

  v3 = ppResult;
  v4 = this;
  if ( ppResult )
  {
    v5 = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( v5 )
    {
      if ( (v5->m_Flags >> 14) & 1 )
      {
        v7 = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
        v8 = Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(v7);
        if ( v8 )
        {
          v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemVehicleComponent>((UFG::SimObjectCVBase *)&v8->vfptr);
          if ( v9 )
          {
            v10 = v4->mpSimObj.m_pPointer;
            if ( !v10 || !((v10->m_Flags >> 14) & 1) )
              v10 = 0i64;
            v6 = 0;
            if ( v10 == v9->m_pTargets[(unsigned __int8)v9->m_pTargetingMap->m_Map.p[13]].m_pTarget.m_pPointer )
              v6 = 1;
          }
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 2979
// RVA: 0x500780
void __fastcall UFG::TSCharacter::Mthd_is_a_passenger(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::CharacterOccupantComponent *v5; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) || !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_16;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::CharacterOccupantComponent *)v3->m_Components.p[44].m_pComponent;
    if ( v5 && v5->mTargetType != 4 && !UFG::CharacterOccupantComponent::IsEnteringOrExiting(v5) )
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    else
LABEL_16:
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 3003
// RVA: 0x503910
void __fastcall UFG::TSCharacter::Mthd_is_the_passenger(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::TSCharacter *v4; // rbx
  UFG::SimObject *v5; // rax
  bool v6; // di
  UFG::TSVehicle *v7; // rax
  UFG::SimObjectVehicle *v8; // rax
  UFG::SimObject *v9; // rdx
  UFG::VehicleOccupantComponent *v10; // rbp
  UFG::SimComponentHolder *v11; // rax
  UFG::SimComponent *v12; // rbx

  v3 = ppResult;
  v4 = this;
  if ( ppResult )
  {
    v5 = this->mpSimObj.m_pPointer;
    v6 = 0;
    if ( v5 )
    {
      if ( (v5->m_Flags >> 14) & 1 )
      {
        v7 = (UFG::TSVehicle *)UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
        v8 = Scaleform::GFx::AS3::ClassTraits::UserDefined::GetFilePtr(v7);
        v9 = v4->mpSimObj.m_pPointer;
        v10 = (UFG::VehicleOccupantComponent *)v8;
        if ( v9 )
        {
          if ( (v9->m_Flags >> 14) & 1 )
          {
            if ( !v9 || !((v9->m_Flags >> 14) & 1) )
              v9 = 0i64;
            v11 = v9->m_Components.p;
            v12 = v11[44].m_pComponent;
            if ( v12
              && v10 == UFG::CharacterOccupantComponent::GetCurrentVehicle((UFG::CharacterOccupantComponent *)v11[44].m_pComponent)
              && LODWORD(v12[1].m_SafePointerList.mNode.mNext) != 4 )
            {
              v6 = 0;
              if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v12) )
                v6 = 1;
            }
          }
        }
      }
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 3038
// RVA: 0x5025D0
void __fastcall UFG::TSCharacter::Mthd_is_local_player(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::SimObjectCharacter *v5; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = UFG::GetLocalPlayer();
    *v4 = (SSInstance *)SSBoolean::pool_new(v3 == (UFG::SimObject *)v5);
  }
}

// File Line: 3051
// RVA: 0x4FF230
void __fastcall UFG::TSCharacter::Mthd_get_trunk_vehicle(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::TargetingSystemVehicleComponent *v5; // rcx
  UFG::TargetingMap *v6; // rdx
  UFG::TargetingSimObject *v7; // r8
  UFG::SimObject *v8; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
      {
        if ( !v3 || !((v3->m_Flags >> 14) & 1) )
          v3 = 0i64;
        v5 = (UFG::TargetingSystemVehicleComponent *)v3->m_Components.p[20].m_pComponent;
        if ( v5 )
        {
          v6 = v5->m_pTargetingMap;
          v7 = v5->m_pTargets;
          if ( v7[(unsigned __int8)v6->m_Map.p[eTARGET_TYPE_VEHICLE_PASSENGER_TRUNK]].m_pTarget.m_pPointer )
          {
            v8 = v7[(unsigned __int8)v6->m_Map.p[eTARGET_TYPE_VEHICLE]].m_pTarget.m_pPointer;
            if ( v8 )
              *v4 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v8);
          }
        }
      }
    }
  }
}

// File Line: 3083
// RVA: 0x4FC2E0
void __fastcall UFG::TSCharacter::Mthd_get_current_vehicle(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::SimComponentHolder *v5; // rax
  UFG::CharacterOccupantComponent *v6; // rbx
  UFG::SimObject *v7; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 && v4 && (v4->m_Flags >> 14) & 1 )
      {
        if ( !v4 || !((v4->m_Flags >> 14) & 1) )
          v4 = 0i64;
        v5 = v4->m_Components.p;
        v6 = (UFG::CharacterOccupantComponent *)v5[44].m_pComponent;
        if ( v6 )
        {
          if ( !UFG::CharacterOccupantComponent::IsEnteringOrExiting((UFG::CharacterOccupantComponent *)v5[44].m_pComponent) )
          {
            v7 = (UFG::SimObject *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v6);
            *v3 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v7);
          }
        }
      }
    }
  }
}

// File Line: 3108
// RVA: 0x4DF0F0
char __fastcall UFG::TSCharacter::Coro_wait_until_outside_vehicle(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *v2; // rdx
  char result; // al

  v2 = this->mpSimObj.m_pPointer;
  if ( !v2 || !((v2->m_Flags >> 14) & 1) )
    goto LABEL_11;
  if ( !v2 || !((v2->m_Flags >> 14) & 1) )
    v2 = 0i64;
  if ( v2->m_Components.p[44].m_pComponent )
    result = 0;
  else
LABEL_11:
    result = 1;
  return result;
}

// File Line: 3125
// RVA: 0x500250
void __fastcall UFG::TSCharacter::Mthd_has_taken_damage(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // bl
  SSInstance **v5; // rdi
  UFG::SimComponent *v6; // rax

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
    {
      v6 = UFG::SimObject::GetComponentOfType(v3, UFG::HitReactionComponent::_TypeUID);
      if ( v6 )
        v4 = *(_DWORD *)(&v6[3].m_SimObjIndex + 1) == 1 && BYTE2(v6[2].m_BoundComponentHandles.mNode.mNext);
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 3147
// RVA: 0x1541890
__int64 UFG::_dynamic_initializer_for__sym_Sync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Sync01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_Sync01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_Sync01__);
}

// File Line: 3148
// RVA: 0x1541850
__int64 UFG::_dynamic_initializer_for__sym_Direction__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Direction", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_Direction, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_Direction__);
}

// File Line: 3156
// RVA: 0x4DE200
char __fastcall UFG::TSCharacter::Coro_sync_to_target(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObjectCVBase *v2; // rdi
  SSInvokedCoroutine *v3; // rsi
  UFG::TSCharacter *v4; // rbx
  int v5; // er15
  float v7; // xmm1_4
  float v8; // xmm7_4
  float weight; // xmm6_4
  char v10; // bp
  UFG::SimComponent *v11; // r14
  UFG::CharacterAnimationComponent *v12; // rax
  __int64 v13; // rdx
  UFG::CharacterAnimationComponent *v14; // rsi
  __int64 v15; // rax
  UFG::TransformNodeComponent *v16; // r14
  Creature *v17; // rdi
  int v18; // er12
  float v19; // xmm0_4

  v2 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v3 = pScope;
  v4 = this;
  if ( !v2 || !((v2->m_Flags >> 14) & 1) )
    return 1;
  v5 = -1;
  if ( !pScope->i_update_count )
  {
    if ( (unsigned int)UFG::qStringCompare(
                         *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data,
                         "POI_Use",
                         -1) )
      return 1;
    v4->mBlendTime = *(float *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64);
  }
  v7 = v4->mBlendTime;
  v8 = UFG::Metrics::msRealTimeDelta_Accurate;
  if ( v7 <= 0.0000099999997 )
    weight = *(float *)&FLOAT_1_0;
  else
    weight = UFG::Metrics::msRealTimeDelta_Accurate / v7;
  v10 = 0;
  if ( weight > 0.99980003 )
  {
    weight = *(float *)&FLOAT_1_0;
    v10 = 1;
  }
  v11 = v2->m_Components.p[20].m_pComponent;
  v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
  v14 = v12;
  if ( v11 )
  {
    if ( v12 )
    {
      v13 = 56i64 * *(unsigned __int8 *)(*(_QWORD *)&v11[1].m_Flags + 34i64);
      v15 = *(_QWORD *)(v13 + *(_QWORD *)&v11[1].m_TypeUID + 40);
      if ( v15 )
      {
        v16 = *(UFG::TransformNodeComponent **)(v15 + 88);
        v17 = v14->mCreature;
        if ( v16 )
        {
          if ( v17 )
          {
            if ( v17->mPose.mRigHandle.mData )
              v18 = Skeleton::GetBoneID(v17->mPose.mRigHandle.mUFGSkeleton, UFG::sym_Sync01.mUID);
            else
              v18 = -1;
            if ( v17->mPose.mRigHandle.mData )
              v5 = Skeleton::GetBoneID(v17->mPose.mRigHandle.mUFGSkeleton, UFG::sym_Direction.mUID);
            UFG::TransformNodeComponent::UpdateWorldTransform(v16);
            Creature::Attach(v17, v18, v5, &v16->mWorldTransform, weight);
          }
        }
      }
    }
  }
  v19 = v4->mBlendTime;
  if ( v19 > 0.0 )
    v4->mBlendTime = v19 - v8;
  if ( v4->mBlendTime <= 0.0 )
    v4->mBlendTime = 0.0;
  if ( v10 )
  {
    if ( v14 )
      Creature::MakeUpright(v14->mCreature, 0.0, v13);
  }
  return v10;
}

// File Line: 3245
// RVA: 0x4DE100
char __fastcall UFG::TSCharacter::Coro_submit_action_request(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::SimObject *v2; // rax
  SSInvokedCoroutine *v3; // r8
  UFG::TSCharacter *v4; // rbx
  UFG::AIScriptInterfaceComponent *v5; // rcx
  SSData **v6; // rdx
  SSInstance *v7; // rdi
  SSInstance *v8; // rsi
  bool v9; // bp

  v2 = this->mpSimObj.m_pPointer;
  v3 = pScope;
  v4 = this;
  if ( !v2 )
    return 1;
  if ( !((v2->m_Flags >> 14) & 1) )
    return 1;
  v5 = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( !v5 )
    return 1;
  v6 = pScope->i_data.i_array_p;
  v7 = (*v6)->i_data_p;
  v8 = v6[1]->i_data_p;
  v9 = v6[2]->i_data_p->i_user_data != 0;
  if ( !v3->i_update_count )
    UFG::AIScriptInterfaceComponent::BeginCommandActionRequest(v5);
  if ( UFG::AIScriptInterfaceComponent::GiveCommand(
         (UFG::AIScriptInterfaceComponent *)v4->mAIScriptInterfaceComponent.m_pSimComponent,
         eSCRIPT_COMMAND_SUBMIT_ACTION_REQUEST) )
  {
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)v4->mAIScriptInterfaceComponent.m_pSimComponent,
      *(const char **)v7->i_user_data);
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)v4->mAIScriptInterfaceComponent.m_pSimComponent,
      *(const char **)v8->i_user_data);
    UFG::AIScriptInterfaceComponent::AddArgument(
      (UFG::AIScriptInterfaceComponent *)v4->mAIScriptInterfaceComponent.m_pSimComponent,
      v9 != 0);
  }
  return (LOBYTE(v4->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) >> 2) & 1;
}

// File Line: 3282
// RVA: 0x4DBC70
bool __fastcall UFG::TSCharacter::Coro_move_to_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rdi
  UFG::SimObject *v3; // rcx
  SSInvokedCoroutine *v4; // rsi
  bool v5; // dl
  UFG::NavComponent *v6; // r14
  bool v7; // r15
  float *v8; // rcx
  float v9; // xmm0_4
  float v10; // xmm1_4
  UFG::TransformNodeComponent *v11; // rbx
  bool v12; // zf
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::TransformNodeComponent *v16; // rbx
  float v17; // xmm6_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float *v24; // rbx
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm3_4
  bool result; // al
  UFG::qVector3 position; // [rsp+30h] [rbp-29h]
  UFG::qVector3 out; // [rsp+40h] [rbp-19h]
  UFG::HavokNavPosition npDestination; // [rsp+50h] [rbp-9h]

  v2 = this;
  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  v5 = pScope->i_update_count == 0;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_22;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v6 = (UFG::NavComponent *)v3->m_Components.p[36].m_pComponent;
    if ( v6 )
    {
      v7 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64;
      if ( v5 )
      {
        v2->mpMoveToActor = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&v4->vfptr, 0);
        v2->mMoveToActorThreshold = *(float *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64);
        v8 = *(float **)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 3) + 8i64) + 32i64);
        v9 = v8[1];
        v10 = v8[2];
        v2->mMoveToActorOffset.x = *v8;
        v2->mMoveToActorOffset.y = v9;
        v2->mMoveToActorOffset.z = v10;
        v2->mMoveToActorIsLocal = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64;
      }
      v11 = (UFG::TransformNodeComponent *)v2->mpMoveToActor->mTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      v12 = v2->mMoveToActorIsLocal == 0;
      v13 = v11->mWorldTransform.v3.y;
      v14 = v11->mWorldTransform.v3.z;
      v15 = v11->mWorldTransform.v3.x;
      position.x = v11->mWorldTransform.v3.x;
      position.y = v13;
      position.z = v14;
      if ( v12 )
      {
        v22 = v13 + v2->mMoveToActorOffset.y;
        v23 = v14 + v2->mMoveToActorOffset.z;
        position.x = v15 + v2->mMoveToActorOffset.x;
        position.y = v22;
        position.z = v23;
      }
      else
      {
        v16 = (UFG::TransformNodeComponent *)v2->mpMoveToActor->mTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v16);
        v17 = v2->mMoveToActorOffset.x;
        v18 = v17;
        v19 = (float)(v17 * v16->mWorldTransform.v0.z) + (float)(v2->mMoveToActorOffset.y * v16->mWorldTransform.v1.z);
        v20 = v2->mMoveToActorOffset.z * v16->mWorldTransform.v2.z;
        v21 = (float)((float)(v18 * v16->mWorldTransform.v0.y)
                    + (float)(v2->mMoveToActorOffset.y * v16->mWorldTransform.v1.y))
            + (float)(v2->mMoveToActorOffset.z * v16->mWorldTransform.v2.y);
        position.x = position.x
                   + (float)((float)((float)(v2->mMoveToActorOffset.y * v16->mWorldTransform.v1.x)
                                   + (float)(v2->mMoveToActorOffset.x * v16->mWorldTransform.v0.x))
                           + (float)(v2->mMoveToActorOffset.z * v16->mWorldTransform.v2.x));
        position.z = position.z + (float)(v19 + v20);
        position.y = position.y + v21;
      }
      if ( !UFG::PlaceOnGround(&out, &position, 0.0, 0.0) )
        out = position;
      UFG::TSCharacter::SetTarget(v2, &out, v2->mMoveToActorThreshold);
      v24 = (float *)v2->mpTargetNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mpTargetNode.m_pPointer);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
      v25 = v24[45];
      v26 = v24[46];
      v27 = v24[44];
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
      npDestination.m_vPosition.y = v25;
      npDestination.m_vPosition.z = v26;
      npDestination.m_vPosition.x = v27;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)*((unsigned int *)v24 + 44),
                                                   (__m128)*((unsigned int *)v24 + 46)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)*((unsigned int *)v24 + 45),
                                                   (__m128)(unsigned int)FLOAT_1_0));
      v28 = UFG::GetNaturalMovementSpeed(eMoveType_Walk);
      UFG::NavComponent::AddGoalPoint(v6, &npDestination, 0, v28, 0.30000001);
      result = UFG::TSCharacter::PathToTarget(v2, v4, 1, v7) != 0;
    }
    else
    {
LABEL_22:
      result = 1;
    }
  }
  else
  {
    SSInvokedCoroutine::suspend(v4);
    result = 0;
  }
  return result;
}

// File Line: 3353
// RVA: 0x4DC130
bool __fastcall UFG::TSCharacter::Coro_move_to_xform(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rdi
  SSInvokedCoroutine *v3; // rsi
  UFG::SimObject *v4; // r8
  float *v5; // rcx
  float v6; // xmm0_4
  float v7; // xmm1_4
  bool v8; // r9
  __int64 v9; // rcx
  UFG::TransformNodeComponent *v10; // rdx
  bool v11; // bl
  bool result; // al
  UFG::qVector3 offset; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      goto LABEL_16;
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    if ( v4->m_Components.p[36].m_pComponent )
    {
      if ( pScope->i_update_count == 0 )
      {
        this->mTransNode = (UFG::TransformNodeComponent *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
        this->mMoveToActorThreshold = *(float *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64);
        v5 = *(float **)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64) + 32i64);
        v6 = v5[1];
        v7 = v5[2];
        v2->mMoveToActorOffset.x = *v5;
        v2->mMoveToActorOffset.y = v6;
        v2->mMoveToActorOffset.z = v7;
        v2->mMoveToActorIsLocal = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64;
      }
      v8 = v2->mMoveToActorIsLocal;
      v9 = *((_QWORD *)pScope->i_data.i_array_p + 5);
      v10 = v2->mTransNode;
      offset.x = v2->mMoveToActorOffset.x;
      offset.y = offset.x;
      offset.z = offset.x;
      v11 = *(_QWORD *)(*(_QWORD *)(v9 + 8) + 32i64) != 0i64;
      UFG::TSCharacter::SetTarget(v2, v10, &offset, v8, v2->mMoveToActorThreshold);
      result = UFG::TSCharacter::PathToTarget(v2, v3, 1, v11) != 0;
    }
    else
    {
LABEL_16:
      result = 1;
    }
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    result = 0;
  }
  return result;
}

// File Line: 3401
// RVA: 0x4DC030
bool __fastcall UFG::TSCharacter::Coro_move_to_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rsi
  SSInvokedCoroutine *v3; // rdi
  UFG::SimObject *v4; // rax
  SSData **v5; // rdx
  UFG::qVector3 *v6; // rbx
  float v7; // xmm6_4
  float *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  bool result; // al
  UFG::qVector3 out; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count == 0 )
    {
      v5 = pScope->i_data.i_array_p;
      v6 = (UFG::qVector3 *)(*v5)->i_data_p->i_user_data;
      v7 = *(float *)&v5[1]->i_data_p->i_user_data;
      v8 = (float *)v5[3]->i_data_p->i_user_data;
      v9 = v8[1] + v6->y;
      v10 = v8[2] + v6->z;
      v6->x = *v8 + v6->x;
      v6->y = v9;
      v6->z = v10;
      UFG::PlaceOnGround(&out, v6, 0.0, 0.0);
      UFG::TSCharacter::SetTarget(v2, v6, v7);
    }
    result = UFG::TSCharacter::PathToTarget(v2, v3, 1, 0) != 0;
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    result = 0;
  }
  return result;
}

// File Line: 3450
// RVA: 0x4DC480
char __fastcall UFG::TSCharacter::Coro_path_to_target_type(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v2; // rbx
  UFG::TSCharacter *v3; // rsi
  UFG::SimObject *v4; // rdi
  UFG::qSymbol *v5; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  UFG::SimComponent *v7; // r8
  __int64 v8; // rcx
  UFG::TransformNodeComponent *v9; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+38h] [rbp-28h]
  UFG::qSymbol result; // [rsp+70h] [rbp+10h]

  v2 = pScope;
  v3 = this;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count != 0 )
      return UFG::TSCharacter::PathToTarget(
               v3,
               v2,
               2,
               *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
    v5 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v6 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v6;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v7 = v4->m_Components.p[20].m_pComponent;
    if ( v7 )
    {
      v8 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + pTrackEnumBinding.m_EnumValue + 8i64)
                     + *(_QWORD *)&v7[1].m_TypeUID
                     + 40);
      if ( v8 )
      {
        v9 = *(UFG::TransformNodeComponent **)(v8 + 88);
        if ( v9 )
        {
          UFG::TSCharacter::SetTarget(
            v3,
            v9,
            *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64) + 32i64),
            *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64,
            *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64) + 32i64));
          v10 = pTrackEnumBinding.mPrev;
          v11 = pTrackEnumBinding.mNext;
          pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
          v11->mPrev = v10;
          pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
          return UFG::TSCharacter::PathToTarget(
                   v3,
                   v2,
                   2,
                   *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
        }
      }
    }
    v12 = pTrackEnumBinding.mPrev;
    v13 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
  SSInvokedCoroutine *v2; // rsi
  UFG::TSCharacter *v3; // rdi
  bool v4; // r10
  SSData **v5; // r9
  bool v6; // r8
  UFG::SimObject *v7; // rcx
  UFG::SimObject *v8; // rdx
  UFG::NavComponent *v9; // r14
  unsigned int v11; // ebx
  SSInvokedCoroutine *v12; // rcx
  UFG::AIScriptInterfaceComponent *v13; // rcx
  __m128 v14; // xmm7
  __m128 v15; // xmm2
  float v16; // xmm1_4
  float v17; // xmm8_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  __m128 v20; // xmm2
  __m128 v21; // xmm5
  float v22; // xmm1_4
  __m128 v23; // xmm10
  float v24; // xmm9_4
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  float v27; // xmm1_4
  float v28; // xmm9_4
  float v29; // xmm2_4
  float v30; // xmm12_4
  float v31; // xmm13_4
  __m128 v32; // xmm5
  __m128 v33; // xmm11
  float v34; // xmm3_4
  UFG::qVector3 direction; // [rsp+38h] [rbp-A0h]
  UFG::qVector3 position; // [rsp+48h] [rbp-90h]
  float v37; // [rsp+58h] [rbp-80h]
  int v38; // [rsp+5Ch] [rbp-7Ch]
  UFG::qVector3 v39; // [rsp+60h] [rbp-78h]
  int v40; // [rsp+6Ch] [rbp-6Ch]
  int v41; // [rsp+70h] [rbp-68h]
  int v42; // [rsp+74h] [rbp-64h]
  float v43; // [rsp+78h] [rbp-60h]
  float v44; // [rsp+7Ch] [rbp-5Ch]
  UFG::qSymbol symbol; // [rsp+128h] [rbp+50h]
  float elapsedTime; // [rsp+130h] [rbp+58h]
  int uid; // [rsp+138h] [rbp+60h]
  UFG::qSymbol *vars0; // [rsp+140h] [rbp+68h]

  v2 = pScope;
  v3 = this;
  v4 = pScope->i_update_count == 0;
  v5 = pScope->i_data.i_array_p;
  v6 = v5[1]->i_data_p->i_user_data != 0;
  v7 = this->mpSimObj.m_pPointer;
  if ( v7 && (v7->m_Flags >> 14) & 1 )
    v8 = v7;
  else
    v8 = 0i64;
  if ( v7 && (v7->m_Flags >> 14) & 1 )
  {
    if ( !v7 || !((v7->m_Flags >> 14) & 1) )
      v7 = 0i64;
    v9 = (UFG::NavComponent *)v7->m_Components.p[36].m_pComponent;
    if ( v9 )
    {
      if ( !v8 )
      {
        SSInvokedCoroutine::suspend(v2);
        return 0;
      }
      v11 = (*v5)->i_data_p->i_user_data;
      if ( v4 )
      {
        v12 = v3->mpNavigationThread.i_obj_p;
        if ( v12 && v3->mpNavigationThread.i_ptr_id == v12->i_ptr_id && v12 != v2 )
          ++v12->i_pending_count;
        v3->mpNavigationThread.i_obj_p = v2;
        v3->mpNavigationThread.i_ptr_id = v2->i_ptr_id;
        if ( v6 )
          v3->mModeFlags |= 2u;
        else
          v3->mModeFlags &= 0xFFFFFFFD;
        BYTE1(v3->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) &= 0x7Fu;
        if ( !UFG::AIScriptInterfaceComponent::GiveCommand(
                (UFG::AIScriptInterfaceComponent *)v3->mAIScriptInterfaceComponent.m_pSimComponent,
                eSCRIPT_COMMAND_FOLLOW_SCRIPTED_PATH,
                v3->mSpeed) )
          return 0;
        vars0 = &symbol;
        symbol.mUID = v11;
        v13 = (UFG::AIScriptInterfaceComponent *)v3->mAIScriptInterfaceComponent.m_pSimComponent;
        goto LABEL_43;
      }
      UFG::NavComponent::PreserveDestination(v9);
      if ( SBYTE1(v3->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) >= 0 )
        return 0;
      if ( !(unsigned __int8)UFG::NavComponent::IsAtDestination(v9) )
      {
        uid = -1;
        elapsedTime = FLOAT_N1_0;
        if ( UFG::NavComponent::GetCurrGoalPointInfo(v9, &position, &direction, &elapsedTime, &uid)
          && elapsedTime > *(float *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64) )
        {
          UFG::NavComponent::ForceGoalPointAdvance(v9);
          v14 = (__m128)LODWORD(direction.x);
          v15 = v14;
          v15.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(direction.y * direction.y))
                          + (float)(direction.z * direction.z);
          if ( v15.m128_f32[0] == 0.0 )
            v16 = 0.0;
          else
            v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
          v17 = v16 * direction.z;
          v18 = direction.y * v16;
          v19 = direction.x * v16;
          v20 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v20.m128_f32[0] == 0.0 )
          {
            v21 = 0i64;
          }
          else
          {
            v21 = (__m128)(unsigned int)FLOAT_1_0;
            v21.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
          }
          v22 = v21.m128_f32[0] * UFG::qVector3::msDirUp.z;
          v25 = v21;
          v25.m128_f32[0] = v21.m128_f32[0] * UFG::qVector3::msDirUp.y;
          v21.m128_f32[0] = v21.m128_f32[0] * UFG::qVector3::msDirUp.x;
          v23 = v21;
          v23.m128_f32[0] = (float)(v21.m128_f32[0] * v18) - (float)(v19 * v25.m128_f32[0]);
          v24 = (float)(v19 * v22) - (float)(v21.m128_f32[0] * v17);
          v25.m128_f32[0] = (float)(v25.m128_f32[0] * v17) - (float)(v22 * v18);
          v26 = v25;
          v26.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24))
                          + (float)(v23.m128_f32[0] * v23.m128_f32[0]);
          if ( v26.m128_f32[0] == 0.0 )
            v27 = 0.0;
          else
            v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
          v23.m128_f32[0] = v23.m128_f32[0] * v27;
          v28 = v24 * v27;
          v29 = v25.m128_f32[0] * v27;
          v30 = (float)(v28 * v19) - (float)(v29 * v18);
          v31 = (float)(v29 * v17) - (float)(v23.m128_f32[0] * v19);
          v32 = v23;
          v32.m128_f32[0] = (float)(v23.m128_f32[0] * v18) - (float)(v28 * v17);
          v33 = v32;
          v33.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31 * v31))
                          + (float)(v30 * v30);
          if ( v33.m128_f32[0] == 0.0 )
            v34 = 0.0;
          else
            v34 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v33));
          v41 = v23.m128_i32[0];
          v42 = 0;
          v43 = v32.m128_f32[0] * v34;
          v44 = v34 * v31;
          v37 = v34 * v30;
          v38 = 0;
          v39 = position;
          v40 = 1065353216;
          UFG::TSActor::TeleportToTransform((UFG::TSActor *)&v3->vfptr, (UFG::qMatrix44 *)&v37);
        }
        if ( !UFG::AIScriptInterfaceComponent::GiveCommand(
                (UFG::AIScriptInterfaceComponent *)v3->mAIScriptInterfaceComponent.m_pSimComponent,
                eSCRIPT_COMMAND_FOLLOW_SCRIPTED_PATH,
                v3->mSpeed) )
          return 0;
        vars0 = &symbol;
        symbol.mUID = v11;
        v13 = (UFG::AIScriptInterfaceComponent *)v3->mAIScriptInterfaceComponent.m_pSimComponent;
LABEL_43:
        UFG::AIScriptInterfaceComponent::AddArgument(v13, (__int64)&symbol);
        return 0;
      }
      BYTE1(v3->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) &= 0x7Fu;
      UFG::TSCharacter::NavigationScriptFinish(v3, v2);
    }
  }
  return 1;
}

// File Line: 3628
// RVA: 0x4DC2D0
char __fastcall UFG::TSCharacter::Coro_path_to_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rdi
  SSInvokedCoroutine *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::TSActor *v5; // rax
  char result; // al

  v2 = this;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count == 0 )
    {
      v5 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
      UFG::TSCharacter::SetTarget(
        v2,
        (UFG::TransformNodeComponent *)v5->mTransformNodeComponent.m_pSimComponent,
        *(UFG::qVector3 **)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 3) + 8i64) + 32i64),
        *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 4) + 8i64) + 32i64) != 0i64,
        *(float *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 1) + 8i64) + 32i64));
    }
    result = UFG::TSCharacter::PathToTarget(v2, v3, 2, 0);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    result = 0;
  }
  return result;
}

// File Line: 3660
// RVA: 0x4DC6A0
char __fastcall UFG::TSCharacter::Coro_path_to_xform(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rdi
  SSInvokedCoroutine *v3; // rbx
  UFG::SimObject *v4; // rax
  SSData **v5; // rdx
  char result; // al

  v2 = this;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count == 0 )
    {
      v5 = pScope->i_data.i_array_p;
      UFG::TSCharacter::SetTarget(
        this,
        (UFG::TransformNodeComponent *)(*v5)->i_data_p->i_user_data,
        (UFG::qVector3 *)v5[3]->i_data_p->i_user_data,
        v5[4]->i_data_p->i_user_data != 0,
        *(float *)&v5[1]->i_data_p->i_user_data);
    }
    result = UFG::TSCharacter::PathToTarget(
               v2,
               v3,
               2,
               *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    result = 0;
  }
  return result;
}

// File Line: 3692
// RVA: 0x4DC390
char __fastcall UFG::TSCharacter::Coro_path_to_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rdi
  SSInvokedCoroutine *v3; // rbx
  UFG::SimObject *v4; // rax
  SSData **v5; // r8
  float *v6; // rdx
  float *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  char result; // al
  UFG::qVector3 pos; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = pScope;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( pScope->i_update_count == 0 )
    {
      v5 = pScope->i_data.i_array_p;
      v6 = (float *)(*v5)->i_data_p->i_user_data;
      v7 = (float *)v5[3]->i_data_p->i_user_data;
      v8 = v7[1] + v6[1];
      pos.x = *v7 + *v6;
      v9 = v7[2];
      pos.y = v8;
      v10 = *(float *)&v5[1]->i_data_p->i_user_data;
      pos.z = v9 + v6[2];
      UFG::TSCharacter::SetTarget(this, &pos, v10);
    }
    result = UFG::TSCharacter::PathToTarget(
               v2,
               v3,
               2,
               *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v3->i_data.i_array_p + 5) + 8i64) + 32i64) != 0i64);
  }
  else
  {
    SSInvokedCoroutine::suspend(pScope);
    result = 0;
  }
  return result;
}

// File Line: 3723
// RVA: 0x50A6E0
void __fastcall UFG::TSCharacter::Mthd_set_speed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  this->mSpeed = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 3733
// RVA: 0x4FEBD0
void __fastcall UFG::TSCharacter::Mthd_get_speed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  unsigned int v5; // xmm0_4
  UFG::CharacterPhysicsComponent *v6; // rcx
  __m128 v7; // xmm2
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = 0;
    if ( v3 )
    {
      v6 = (UFG::CharacterPhysicsComponent *)v3->m_Components.p[27].m_pComponent;
      if ( v6 )
      {
        UFG::CharacterPhysicsComponent::GetVelocity(v6, &result);
        v7 = (__m128)LODWORD(result.x);
        v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(result.y * result.y))
                       + (float)(result.z * result.z);
        v5 = (unsigned __int128)_mm_sqrt_ps(v7);
      }
    }
    *v4 = SSInstance::pool_new(SSBrain::c_real_class_p, v5);
  }
}

// File Line: 3761
// RVA: 0x508760
void __fastcall UFG::TSCharacter::Mthd_set_ignore_ambient_stimuli(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x400ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFBFFui64;
      }
    }
  }
}

// File Line: 3776
// RVA: 0x4F4970
void __fastcall UFG::TSCharacter::Mthd_allow_jog(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 1ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFFEui64;
      }
    }
  }
}

// File Line: 3796
// RVA: 0x502500
void __fastcall UFG::TSCharacter::Mthd_is_jog_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && v5->mBooleans.mBits[0] & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3819
// RVA: 0x4F4A30
void __fastcall UFG::TSCharacter::Mthd_allow_sprint(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 2ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFFDui64;
      }
    }
  }
}

// File Line: 3839
// RVA: 0x503240
void __fastcall UFG::TSCharacter::Mthd_is_sprint_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 1) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3862
// RVA: 0x4F4850
void __fastcall UFG::TSCharacter::Mthd_allow_combat_prop_use(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 4ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFFBui64;
      }
    }
  }
}

// File Line: 3881
// RVA: 0x5012C0
void __fastcall UFG::TSCharacter::Mthd_is_combat_prop_use_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 2) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3903
// RVA: 0x4F47F0
void __fastcall UFG::TSCharacter::Mthd_allow_action_hijack(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 8ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFF7ui64;
      }
    }
  }
}

// File Line: 3917
// RVA: 0x500820
void __fastcall UFG::TSCharacter::Mthd_is_action_hijack_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 3) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3932
// RVA: 0x4F4AF0
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_exit(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x10ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFEFui64;
      }
    }
  }
}

// File Line: 3946
// RVA: 0x503DA0
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_exit_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 4) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3961
// RVA: 0x4F4A90
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_eject(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x20ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFDFui64;
      }
    }
  }
}

// File Line: 3975
// RVA: 0x503D40
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_eject_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 5) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 3990
// RVA: 0x4F4B50
void __fastcall UFG::TSCharacter::Mthd_allow_vehicle_shooting(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x40ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFFBFui64;
      }
    }
  }
}

// File Line: 4004
// RVA: 0x503E00
void __fastcall UFG::TSCharacter::Mthd_is_vehicle_shooting_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && (LOBYTE(v5->mBooleans.mBits[0]) >> 6) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4019
// RVA: 0x4F49D0
void __fastcall UFG::TSCharacter::Mthd_allow_sneak_attack(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x80ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFF7Fui64;
      }
    }
  }
}

// File Line: 4033
// RVA: 0x5031E0
void __fastcall UFG::TSCharacter::Mthd_is_sneak_attack_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && SLOBYTE(v5->mBooleans.mBits[0]) < 0 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4048
// RVA: 0x4F4910
void __fastcall UFG::TSCharacter::Mthd_allow_hostage_release(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x100ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFEFFui64;
      }
    }
  }
}

// File Line: 4062
// RVA: 0x501980
void __fastcall UFG::TSCharacter::Mthd_is_hostage_release_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && ((unsigned __int16)LODWORD(v5->mBooleans.mBits[0]) >> 8) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4077
// RVA: 0x4F48B0
void __fastcall UFG::TSCharacter::Mthd_allow_equip_stowed_weapon(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p->i_user_data )
          v5->mBooleans.mBits[0] |= 0x200ui64;
        else
          v5->mBooleans.mBits[0] &= 0xFFFFFFFFFFFFFDFFui64;
      }
    }
  }
}

// File Line: 4091
// RVA: 0x501370
void __fastcall UFG::TSCharacter::Mthd_is_equip_stowed_weapon_allowed(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimObjectCharacterPropertiesComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3
      && (v3->m_Flags >> 14) & 1
      && (v5 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v3)) != 0i64
      && ((unsigned __int64)LODWORD(v5->mBooleans.mBits[0]) >> 9) & 1 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 4106
// RVA: 0x4F3770
void __fastcall UFG::TSCharacter::Mthd_action_request_disable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rdi
  UFG::AICharacterControllerBaseComponent *v5; // rbx
  unsigned int action_request; // [rsp+30h] [rbp+8h]

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        {
          if ( Intention::GetActionRequest(
                 *(const char **)(*v4->i_data.i_array_p)->i_data_p->i_user_data,
                 &action_request) )
          {
            v5->m_ActionRequestMask.mBits[(signed __int64)(signed int)action_request >> 6] &= ~(1i64 << (action_request & 0x3F));
          }
        }
      }
    }
  }
}

// File Line: 4131
// RVA: 0x5084B0
void __fastcall UFG::TSCharacter::Mthd_set_free_aim_intention_xform(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInvokedMethod *v4; // rbp
  UFG::AimingPlayerComponent *v5; // rax
  UFG::TransformNodeComponent *v6; // rdi
  UFG::AimingPlayerComponent *v7; // rsi
  unsigned __int64 v8; // rbx
  float v9; // xmm2_4
  float v10; // xmm5_4
  __m128 v11; // xmm6
  float v12; // xmm3_4
  __m128 v13; // xmm4
  UFG::qVector3 vDirection; // [rsp+20h] [rbp-28h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>((UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer);
      v6 = (UFG::TransformNodeComponent *)v3->m_Components.p[2].m_pComponent;
      v7 = v5;
      if ( v5 )
      {
        if ( v6 )
        {
          v8 = (*v4->i_data.i_array_p)->i_data_p->i_user_data;
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8);
          UFG::TransformNodeComponent::UpdateWorldTransform(v6);
          v11 = (__m128)*(unsigned int *)(v8 + 180);
          v9 = 0.0;
          v10 = *(float *)(v8 + 176) - v6->mWorldTransform.v3.x;
          v11.m128_f32[0] = v11.m128_f32[0] - v6->mWorldTransform.v3.y;
          v12 = *(float *)(v8 + 184) - v6->mWorldTransform.v3.z;
          v13 = v11;
          v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10))
                          + (float)(v12 * v12);
          if ( v13.m128_f32[0] != 0.0 )
            v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
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
void __fastcall UFG::TSCharacter::Mthd_enable_pathing_on_material(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::NavComponent *v4; // rdi
  SSData **v5; // rcx
  SSInstance *v6; // rbx
  bool v7; // si
  hkaiUFGMaterials v8; // edx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v4 = (UFG::NavComponent *)v3->m_Components.p[36].m_pComponent;
      if ( v4 )
      {
        v5 = pScope->i_data.i_array_p;
        v6 = (*v5)->i_data_p;
        v7 = v5[1]->i_data_p->i_user_data != 0;
        if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v6->i_user_data, "generic", -1) )
        {
          if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v6->i_user_data, "road", -1) )
          {
            if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v6->i_user_data, "sidewalk", -1) )
            {
              if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v6->i_user_data, "grass", -1) )
              {
                if ( (unsigned int)UFG::qStringCompareInsensitive(*(const char **)v6->i_user_data, "water", -1) )
                  return;
                v8 = 64;
              }
              else
              {
                v8 = 8;
              }
            }
            else
            {
              v8 = 4;
            }
          }
          else
          {
            v8 = 2;
          }
        }
        else
        {
          v8 = 1;
        }
        UFG::NavComponent::EnablePathingOnMaterial(v4, v8, v7);
      }
    }
  }
}

// File Line: 4185
// RVA: 0x4F9160
void __fastcall UFG::TSCharacter::Mthd_enable_sloppy_freerunning(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponent *v4; // r8

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = v3->m_Components.p[36].m_pComponent;
    if ( v4 )
      LOBYTE(v4[2].m_BoundComponentHandles.mNode.mPrev) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 4200
// RVA: 0x4F8AF0
void __fastcall UFG::TSCharacter::Mthd_enable_freerunning(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponent *v4; // r8
  int v5; // eax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v4 = v3->m_Components.p[36].m_pComponent;
      if ( v4 )
      {
        if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
        {
          LODWORD(v4[3].vfptr) |= 1u;
        }
        else
        {
          v5 = (int)v4[3].vfptr;
          LOBYTE(v4[3].vfptr) = 0;
          LODWORD(v4[3].vfptr) |= (unsigned __int8)(v5 & 0xFE);
        }
      }
    }
  }
}

// File Line: 4225
// RVA: 0x4F3800
void __fastcall UFG::TSCharacter::Mthd_action_request_enable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  SSInvokedMethod *v4; // rdi
  UFG::AICharacterControllerBaseComponent *v5; // rbx
  unsigned int action_request; // [rsp+30h] [rbp+8h]

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
      if ( v5 )
      {
        if ( (*v4->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
        {
          if ( Intention::GetActionRequest(
                 *(const char **)(*v4->i_data.i_array_p)->i_data_p->i_user_data,
                 &action_request) )
          {
            v5->m_ActionRequestMask.mBits[(signed __int64)(signed int)action_request >> 6] |= 1i64 << (action_request & 0x3F);
          }
        }
      }
    }
  }
}

// File Line: 4251
// RVA: 0x4F3890
void __fastcall UFG::TSCharacter::Mthd_action_request_enable_all(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCVBase *v3; // rcx
  UFG::AICharacterControllerBaseComponent *v4; // rax

  v3 = (UFG::SimObjectCVBase *)this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(v3);
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
char __fastcall UFG::TSCharacter::PathToTarget(UFG::TSCharacter *this, SSInvokedCoroutine *pScope, int command, bool terminateOnFail)
{
  SSInvokedCoroutine *v4; // rbx
  bool v5; // r14
  bool v6; // dl
  int v7; // er15
  UFG::TSCharacter *v8; // rdi
  SSInvokedCoroutine *v9; // rcx
  UFG::SimObject *v10; // rcx
  UFG::AiPathGoalMode v11; // esi
  UFG::NavComponent *v12; // rbp
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float fDestinationTolerance; // ST20_4
  UFG::HavokNavPosition npDestination; // [rsp+30h] [rbp-58h]

  v4 = pScope;
  v5 = terminateOnFail;
  v6 = pScope->i_update_count == 0;
  v7 = command;
  v8 = this;
  if ( v6 )
  {
    v9 = this->mpNavigationThread.i_obj_p;
    if ( v9 && v8->mpNavigationThread.i_ptr_id == v9->i_ptr_id && v9 != v4 )
      ++v9->i_pending_count;
    v8->mpNavigationThread.i_obj_p = v4;
    v8->mpNavigationThread.i_ptr_id = v4->i_ptr_id;
  }
  v10 = v8->mpSimObj.m_pPointer;
  if ( v10 && (v10->m_Flags >> 14) & 1 )
  {
    v11 = 0;
    if ( !v10 || !((v10->m_Flags >> 14) & 1) )
      v10 = 0i64;
    v12 = (UFG::NavComponent *)v10->m_Components.p[36].m_pComponent;
  }
  else
  {
    v11 = 0;
    v12 = 0i64;
  }
  if ( v8->mAIScriptInterfaceComponent.m_pSimComponent && v12 && v8->mpTargetNode.m_pPointer )
  {
    if ( v6 )
    {
      if ( *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 2) + 8i64) + 32i64) )
        v8->mModeFlags |= 2u;
      else
        v8->mModeFlags &= 0xFFFFFFFD;
LABEL_25:
      v13 = (UFG::TransformNodeComponent *)v8->mpTargetNode.m_pPointer;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v8->mpTargetNode.m_pPointer);
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable';
      LOBYTE(v11) = v7 == eSCRIPT_COMMAND_MOVE_DIRECTLY_TO_POSITION;
      v14 = v13->mWorldTransform.v3.y;
      v15 = v13->mWorldTransform.v3.z;
      v16 = v13->mWorldTransform.v3.x;
      npDestination.m_bValid = 0;
      *(_QWORD *)&npDestination.m_packedKey = -1i64;
      npDestination.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable';
      npDestination.m_vPosition.x = v16;
      npDestination.m_vPosition.y = v14;
      npDestination.m_vPosition.z = v15;
      fDestinationTolerance = v8->mTargetThreshold;
      npDestination.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.x),
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.z)),
                                                 _mm_unpacklo_ps(
                                                   (__m128)LODWORD(v13->mWorldTransform.v3.y),
                                                   (__m128)(unsigned int)FLOAT_1_0));
      UFG::NavComponent::AddGoalPoint(v12, &npDestination, v11, -1.0, fDestinationTolerance);
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)v8->mAIScriptInterfaceComponent.m_pSimComponent,
        (UFG::eScriptCommand)v7,
        v8->mSpeed);
      return 0;
    }
    if ( UFG::TSCharacter::IsAtTarget(v8) )
    {
      UFG::TSCharacter::NavigationScriptFinish(v8, v4);
    }
    else if ( !v5 || !UFG::NavComponent::IsDestinationUnreachable(v12) )
    {
      goto LABEL_25;
    }
  }
  else if ( v8->mpNavigationThread.i_obj_p == v4 )
  {
    v8->mpNavigationThread.i_obj_p = 0i64;
    v8->mpNavigationThread.i_ptr_id = 0;
  }
  return 1;
}

// File Line: 4327
// RVA: 0x4DD110
bool __fastcall UFG::TSCharacter::Coro_rotate_dir(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rbx
  SSInvokedCoroutine *v3; // rcx
  bool result; // al
  float v5; // xmm2_4
  UFG::qVector3 *v6; // rdi
  float v7; // xmm4_4
  float v8; // xmm5_4
  __m128 v9; // xmm3
  UFG::SimObject *v10; // rcx
  float v11; // xmm1_4
  UFG::qVector3 direction; // [rsp+20h] [rbp-18h]

  v2 = this;
  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    v5 = 0.0;
    v6 = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v7 = v6->y;
    v8 = v6->z;
    v9 = (__m128)LODWORD(v6->x);
    v9.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v7 * v7)) + (float)(v8 * v8);
    if ( v9.m128_f32[0] != 0.0 )
      v5 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
    v10 = this->mpSimObj.m_pPointer;
    v11 = v5 * v6->x;
    direction.z = v5 * v8;
    direction.y = v5 * v7;
    direction.x = v11;
    if ( !v10 || !((v10->m_Flags >> 14) & 1) )
      v10 = 0i64;
    if ( UFG::IsFacingDirection(v10, &direction, -1.0) )
    {
      result = 1;
    }
    else
    {
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)v2->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        v6);
      result = 0;
    }
  }
  else
  {
    v3 = this->mpNavigationThread.i_obj_p;
    if ( v3 && v2->mpNavigationThread.i_ptr_id == v3->i_ptr_id && v3 != pScope )
      ++v3->i_pending_count;
    v2->mpNavigationThread.i_obj_p = pScope;
    v2->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    result = 0;
  }
  return result;
}

// File Line: 4361
// RVA: 0x4DD250
bool __fastcall UFG::TSCharacter::Coro_rotate_pos(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rbx
  SSInvokedCoroutine *v3; // rcx
  bool result; // al
  UFG::SimObject *v5; // rcx
  UFG::qVector3 *v6; // rdi

  v2 = this;
  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    v5 = this->mpSimObj.m_pPointer;
    v6 = (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v5 && (v5->m_Flags >> 14) & 1 )
    {
      if ( UFG::IsFacingPosition(v5, v6, -1.0) )
        return 1;
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)v2->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        v6);
    }
    result = 0;
  }
  else
  {
    v3 = this->mpNavigationThread.i_obj_p;
    if ( v3 && v2->mpNavigationThread.i_ptr_id == v3->i_ptr_id && v3 != pScope )
      ++v3->i_pending_count;
    v2->mpNavigationThread.i_obj_p = pScope;
    v2->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    result = 0;
  }
  return result;
}

// File Line: 4397
// RVA: 0x4DD030
bool __fastcall UFG::TSCharacter::Coro_rotate_actor(UFG::TSCharacter *this, SSInvokedCoroutine *pScope)
{
  UFG::TSCharacter *v2; // rbx
  SSInvokedCoroutine *v3; // rcx
  bool result; // al
  UFG::SimComponent *v5; // rdi
  UFG::SimObject *v6; // rcx

  v2 = this;
  if ( !this->mAIScriptInterfaceComponent.m_pSimComponent )
    return 1;
  if ( pScope->i_update_count )
  {
    v5 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0)->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
    v6 = v2->mpSimObj.m_pPointer;
    if ( !v6 || !((v6->m_Flags >> 14) & 1) )
      v6 = 0i64;
    if ( UFG::IsFacingPosition(v6, (UFG::qVector3 *)&v5[2].m_BoundComponentHandles, -1.0) )
    {
      result = 1;
    }
    else
    {
      UFG::AIScriptInterfaceComponent::GiveCommand(
        (UFG::AIScriptInterfaceComponent *)v2->mAIScriptInterfaceComponent.m_pSimComponent,
        eSCRIPT_COMMAND_TURN_TO_FACE_POSITION,
        (UFG::TransformNodeComponent *)v5);
      result = 0;
    }
  }
  else
  {
    v3 = this->mpNavigationThread.i_obj_p;
    if ( v3 && v2->mpNavigationThread.i_ptr_id == v3->i_ptr_id && v3 != pScope )
      ++v3->i_pending_count;
    v2->mpNavigationThread.i_obj_p = pScope;
    v2->mpNavigationThread.i_ptr_id = pScope->i_ptr_id;
    result = 0;
  }
  return result;
}

// File Line: 4429
// RVA: 0x4E08F0
void __fastcall UFG::TSCharacter::EntityDeathHandler(UFG::Event *thisEvent)
{
  UFG::SimObjectCharacter *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::TSActorComponent *v3; // rdi
  SSActorClass *v4; // rcx
  SSClass *v5; // rcx
  UFG::TSCharacter *v6; // rdi
  SSInvokedCoroutine *v7; // rax
  UFG::ProgressionTracker *v8; // rax
  UFG::CopSystem *v9; // rax
  unsigned int v10; // edx
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // rax

  v1 = (UFG::SimObjectCharacter *)thisEvent[1].mNext;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = (UFG::TSActorComponent *)v1->m_Components.p[3].m_pComponent;
      else
        v3 = (UFG::TSActorComponent *)((v2 >> 12) & 1 ? v1->m_Components.p[2].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v1->vfptr,
                                                                                               UFG::TSActorComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    if ( v3 )
    {
      v4 = (SSActorClass *)UFG::TSActorComponent::GetActor(v3)->i_class_p;
      if ( UFG::SkookumMgr::mspCharacterClass == v4
        || (v5 = v4->i_superclass_p) != 0i64
        && SSClass::is_class(v5, (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr) )
      {
        v6 = (UFG::TSCharacter *)UFG::TSActorComponent::GetActor(v3);
        UFG::TSCharacter::ClearTarget(v6);
        v7 = v6->mpNavigationThread.i_obj_p;
        if ( v7 && v6->mpNavigationThread.i_ptr_id == v7->i_ptr_id )
          ++v7->i_pending_count;
        v6->mpNavigationThread.i_obj_p = 0i64;
        v6->mpNavigationThread.i_ptr_id = 0;
        if ( v1 == UFG::GetLocalPlayer() )
        {
          v8 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetRestoreType(v8, RestoreType_Hospital, 1);
          UFG::MissionFailConditionComponent::FailObject(
            (UFG::SimObject *)&v1->vfptr,
            (UFG::qSymbol *)&qSymbol_DeathFailCaption.mUID);
          v9 = UFG::CopSystem::Instance();
          v10 = UI_HASH_CLEANUPMINIGAME_15;
          v9->mStats.mFinishReason = 2;
          UFG::UIScreenManagerBase::queueMessage(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            v10,
            0xFFFFFFFF);
        }
        else
        {
          v11 = v1->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = v1->m_Components.p[8].m_pComponent;
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
            {
              v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v1->vfptr,
                      UFG::MissionFailConditionComponent::_TypeUID);
            }
            else if ( (v11 >> 12) & 1 )
            {
              v12 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v1->vfptr,
                      UFG::MissionFailConditionComponent::_TypeUID);
            }
            else
            {
              v12 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v1->vfptr,
                      UFG::MissionFailConditionComponent::_TypeUID);
            }
          }
          else
          {
            v12 = v1->m_Components.p[8].m_pComponent;
          }
          if ( v12
            && (BYTE5(v12[1].m_BoundComponentHandles.mNode.mPrev) || BYTE6(v12[1].m_BoundComponentHandles.mNode.mPrev)) )
          {
            UFG::MissionFailConditionComponent::FailObject(
              (UFG::SimObject *)&v1->vfptr,
              (UFG::qSymbol *)&qSymbol_DeathFailCaption.mUID);
          }
        }
      }
    }
  }
}            (UFG::qSymbol *)&qSymbol_DeathFailCaption.mUID);
          }
        }
      }

// File Line: 4476
// RVA: 0x50B9D0
void __fastcall UFG::TSCharacter::Mthd_standing_get(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v3; // ebx
  SSInstance **v4; // r14
  UFG::TSCharacter *v5; // rsi
  UFG::SimObjectCharacter *v6; // rdi
  UFG::GameStatTracker *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *v9; // rcx

  v3 = 0;
  v4 = ppResult;
  v5 = this;
  if ( ppResult )
  {
    v6 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    if ( !v6 || !((v6->m_Flags >> 14) & 1) )
      v6 = 0i64;
    if ( v6 == UFG::GetLocalPlayer() )
    {
      v7 = UFG::GameStatTracker::Instance();
      v3 = UFG::GameStatTracker::GetFaceLevel(v7);
    }
    else
    {
      v8 = v5->mpSimObj.m_pPointer;
      if ( v8 && (v8->m_Flags >> 14) & 1 )
      {
        if ( !v8 || !((v8->m_Flags >> 14) & 1) )
          v8 = 0i64;
        v9 = v8->m_Components.p[45].m_pComponent;
        if ( v9 )
          v3 = (unsigned int)v9[3].m_pSimObject;
      }
    }
  }
  *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
}

// File Line: 4502
// RVA: 0x50BAA0
void __fastcall UFG::TSCharacter::Mthd_standing_get_targets(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rsi
  UFG::TSCharacter *v4; // rbx
  unsigned int v5; // edi
  UFG::SimObject *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // r8
  UFG::SimObjectCharacter *v11; // rbx
  UFG::GameStatTracker *v12; // rax
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v15; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v16; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v3 = ppResult;
  v4 = this;
  v5 = 0;
  v6 = this->mpSimObj.m_pPointer;
  if ( v6 && (v6->m_Flags >> 14) & 1 )
  {
    v7 = UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v8 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v8;
      pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue < 0x5B )
    {
      v9 = v4->mpSimObj.m_pPointer;
      if ( v9 )
      {
        if ( (v9->m_Flags >> 14) & 1 )
        {
          v10 = v9->m_Components.p[20].m_pComponent;
          if ( v10 )
          {
            v11 = *(UFG::SimObjectCharacter **)(56i64
                                              * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags
                                                                   + pTrackEnumBinding.m_EnumValue
                                                                   + 8i64)
                                              + *(_QWORD *)&v10[1].m_TypeUID
                                              + 40);
            if ( v11 )
            {
              if ( v11 == UFG::GetLocalPlayer() )
              {
                v12 = UFG::GameStatTracker::Instance();
                v5 = UFG::GameStatTracker::GetFaceLevel(v12);
              }
              else
              {
                v13 = v11->m_Flags;
                if ( (v13 >> 14) & 1 )
                {
                  v14 = v11->m_Components.p[45].m_pComponent;
                }
                else if ( (v13 & 0x8000u) == 0 )
                {
                  if ( (v13 >> 13) & 1 )
                  {
                    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)&v11->vfptr,
                            UFG::FaceActionComponent::_TypeUID);
                  }
                  else if ( (v13 >> 12) & 1 )
                  {
                    v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                            (UFG::SimObjectGame *)&v11->vfptr,
                            UFG::FaceActionComponent::_TypeUID);
                  }
                  else
                  {
                    v14 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v11->vfptr,
                            UFG::FaceActionComponent::_TypeUID);
                  }
                }
                else
                {
                  v14 = UFG::SimObjectGame::GetComponentOfTypeHK(
                          (UFG::SimObjectGame *)&v11->vfptr,
                          UFG::FaceActionComponent::_TypeUID);
                }
                if ( v14 )
                  v5 = (unsigned int)v14[3].m_pSimObject;
              }
            }
          }
        }
      }
    }
    v15 = pTrackEnumBinding.mPrev;
    v16 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v16->mPrev = v15;
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
}

// File Line: 4556
// RVA: 0x502380
void __fastcall UFG::TSCharacter::Mthd_is_in_water(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // dl
  SSInstance **v5; // rbx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
        v4 = UFG::SimObjectUtility::IsInWater(v3);
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 4574
// RVA: 0x50AEC0
void __fastcall UFG::TSCharacter::Mthd_set_target_to_choose_targets_near(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::TSCharacter *v4; // r15
  SSData *v5; // rax
  float *v6; // rbp
  float *v7; // r14
  const char ***v8; // rsi
  UFG::eTargetTypeEnum v9; // edi
  const char **v10; // rbx
  UFG::ActiveAIEntityComponent *v11; // rax
  float v12; // xmm1_4

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = v3[2];
  v6 = (float *)&v3[1]->i_data_p->i_user_data;
  v7 = (float *)&v5->i_data_p->i_user_data;
  v8 = (const char ***)&(*v3)->i_data_p->i_user_data;
  if ( (*v3)->i_data_p != (SSInstance *)-32i64
    && v3[1]->i_data_p != (SSInstance *)-32i64
    && v5->i_data_p != (SSInstance *)-32i64
    && this->mActiveAIEntityComponent.m_pSimComponent )
  {
    v9 = 0;
    v10 = UFG::TargetTypeEnumNames;
    do
    {
      if ( !(unsigned int)UFG::qStringCompare(**v8, *v10, -1) )
        break;
      ++v10;
      ++v9;
    }
    while ( (signed __int64)v10 < (signed __int64)UFG::AttackPhaseEnumNames );
    if ( v9 < NUM_TARGET_TYPES )
    {
      v11 = (UFG::ActiveAIEntityComponent *)v4->mActiveAIEntityComponent.m_pSimComponent;
      v12 = *v7;
      v11->m_MaxDistanceFromTargetToStayNear = *v6;
      v11->m_MaxDistanceFromTargetToStayNearHysteresis = v12;
      v11->m_TargetToStayNear = v9;
    }
  }
}

// File Line: 4599
// RVA: 0x5087C0
void __fastcall UFG::TSCharacter::Mthd_set_interacting_with_vehicle_heuristic(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    BYTE2(v3[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE2(v3[32].m_BoundComponentHandles.mNode.mPrev) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
}

// File Line: 4611
// RVA: 0x507210
void __fastcall UFG::TSCharacter::Mthd_set_attack_timer(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::SimObject *v4; // rcx
  UFG::HitReactionComponent *v5; // rcx

  v3 = pScope->i_data.i_array_p;
  if ( (*v3)->i_data_p != (SSInstance *)-32i64 )
  {
    v4 = this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 )
      {
        if ( !v4 || !((v4->m_Flags >> 14) & 1) )
          v4 = 0i64;
        v5 = (UFG::HitReactionComponent *)v4->m_Components.p[15].m_pComponent;
        if ( v5 )
          v5->mStateVariables.mAttackTimer = *(float *)&(*v3)->i_data_p->i_user_data;
      }
    }
  }
}

// File Line: 4630
// RVA: 0x4F8730
void __fastcall UFG::TSCharacter::Mthd_distance_target(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  float distance; // [rsp+40h] [rbp+18h]
  float distance_2d; // [rsp+48h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    distance = 0.0;
    if ( !UFG::TSCharacter::GetDistanceToTarget(this, pScope, &distance, &distance_2d) )
      distance = 0.0;
    *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(distance));
  }
}

// File Line: 4644
// RVA: 0x4F8790
void __fastcall UFG::TSCharacter::Mthd_distance_target_2d(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  float distance_2d; // [rsp+40h] [rbp+18h]
  float distance; // [rsp+48h] [rbp+20h]

  if ( ppResult )
  {
    v3 = ppResult;
    distance_2d = 0.0;
    if ( UFG::TSCharacter::GetDistanceToTarget(this, pScope, &distance, &distance_2d) )
    {
      *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(distance_2d));
    }
    else
    {
      distance_2d = 0.0;
      *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, 0i64);
    }
  }
}

// File Line: 4666
// RVA: 0x507BC0
void __fastcall UFG::TSCharacter::Mthd_set_combat_region(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::AIEntityComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::AIEntityComponent *)v3->m_Components.p[22].m_pComponent;
    if ( v4 )
      UFG::AIEntityComponent::SetCombatRegion(
        v4,
        (UFG::CombatRegion *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 4679
// RVA: 0x507800
void __fastcall UFG::TSCharacter::Mthd_set_can_gain_attack_rights(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::ActiveAIEntityComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::ActiveAIEntityComponent *)v3->m_Components.p[5].m_pComponent;
    if ( v5 )
      BYTE1(v5->m_pDesiredTarget[6].mNext) ^= (BYTE1(v5->m_pDesiredTarget[6].mNext) ^ 16
                                                                                    * ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 0x10;
  }
}

// File Line: 4693
// RVA: 0x508260
void __fastcall UFG::TSCharacter::Mthd_set_fake_has_hostage(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[5].m_pComponent;
    if ( v5 )
      BYTE1(v5[32].m_BoundComponentHandles.mNode.mPrev) ^= (BYTE1(v5[32].m_BoundComponentHandles.mNode.mPrev) ^ 32 * ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 0x20;
  }
}

// File Line: 4707
// RVA: 0x4FBCB0
void __fastcall UFG::TSCharacter::Mthd_get_can_gain_attack_rights(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::AttackRightsComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( !v3 || !((v3->m_Flags >> 14) & 1) )
          v3 = 0i64;
        v4 = (UFG::AttackRightsComponent *)v3->m_Components.p[5].m_pComponent;
        if ( v4 )
          *ppResult = (SSInstance *)SSBoolean::pool_new((BYTE1(v4->m_pAttackSlot[0][1][19].m_pPointer) >> 4) & 1);
      }
    }
  }
}

// File Line: 4723
// RVA: 0x4E10D0
char __fastcall UFG::TSCharacter::GetDistanceToTarget(UFG::TSCharacter *this, SSInvokedMethod *pScope, float *distance, float *distance_2d)
{
  float *v4; // r14
  float *v5; // r15
  UFG::TSCharacter *v6; // rdi
  UFG::TransformNodeComponent *v7; // rbx
  char v8; // si
  UFG::SimObject *v9; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rax
  __int64 v11; // rdx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  UFG::SimObject *v14; // rcx
  UFG::SimComponent *v15; // r8
  __int64 v16; // rcx
  UFG::SimComponent *v17; // rdi
  float v18; // xmm6_4
  __m128 v19; // xmm8
  __m128 v20; // xmm7
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-58h]
  UFG::qSymbol result; // [rsp+A0h] [rbp+20h]

  v4 = distance_2d;
  v5 = distance;
  v6 = this;
  v7 = 0i64;
  *distance = 0.0;
  *distance_2d = 0.0;
  v8 = 0;
  v9 = this->mpSimObj.m_pPointer;
  if ( !v9 || !((v9->m_Flags >> 14) & 1) )
    return 0;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gTargetTypeEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gTargetTypeEnum, &pTrackEnumBinding);
  }
  else
  {
    v10 = UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v10;
    pTrackEnumBinding.mNext = &UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gTargetTypeEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v11 = pTrackEnumBinding.m_EnumValue;
  v12 = pTrackEnumBinding.mPrev;
  v13 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v13->mPrev = v12;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  if ( (unsigned int)v11 < 0x5B )
  {
    v14 = v6->mpSimObj.m_pPointer;
    if ( v14 )
    {
      if ( (v14->m_Flags >> 14) & 1 )
      {
        v15 = v14->m_Components.p[20].m_pComponent;
        if ( v15 )
        {
          v16 = *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v15[1].m_Flags + v11 + 8)
                          + *(_QWORD *)&v15[1].m_TypeUID
                          + 40);
          if ( v16 )
            v7 = *(UFG::TransformNodeComponent **)(v16 + 88);
          if ( v7 )
          {
            v17 = v6->mTransformNodeComponent.m_pSimComponent;
            if ( v17 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v17);
              v18 = *(float *)&v17[2].m_BoundComponentHandles.mNode.mPrev;
              v19 = (__m128)HIDWORD(v17[2].m_BoundComponentHandles.mNode.mPrev);
              v20 = (__m128)LODWORD(v17[2].m_BoundComponentHandles.mNode.mNext);
              UFG::TransformNodeComponent::UpdateWorldTransform(v7);
              v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] - v7->mWorldTransform.v3.y)
                                      * (float)(v19.m128_f32[0] - v7->mWorldTransform.v3.y))
                              + (float)((float)(v18 - v7->mWorldTransform.v3.x) * (float)(v18 - v7->mWorldTransform.v3.x));
              v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] - v7->mWorldTransform.v3.z)
                                      * (float)(v20.m128_f32[0] - v7->mWorldTransform.v3.z))
                              + v19.m128_f32[0];
              *(_DWORD *)v5 = (unsigned __int128)_mm_sqrt_ps(v20);
              *(_DWORD *)v4 = (unsigned __int128)_mm_sqrt_ps(v19);
              v8 = 1;
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
void __fastcall UFG::TSCharacter::Mthd_standing_adjust(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  signed int v4; // ebx
  int v5; // ebx
  UFG::GameStatTracker *v6; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v4 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
      v5 = (signed int)(float)(UFG::PlayerBuffTracker::GetFaceXPBonusPercent() * (float)v4) + v4;
      v6 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::ApplyDelta(v6, Standing, v5);
    }
  }
}

// File Line: 4802
// RVA: 0x50BCC0
void __fastcall UFG::TSCharacter::Mthd_standing_set(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInstance *v4; // rbx
  UFG::GameStatTracker *v5; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v4 = (*pScope->i_data.i_array_p)->i_data_p;
      v5 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v5, Standing, v4->i_user_data);
    }
  }
}

// File Line: 4816
// RVA: 0x4F95A0
void __fastcall UFG::TSCharacter::Mthd_face_get_action(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  unsigned int v4; // er9
  SSInstance **v5; // rbx
  signed int v6; // er10
  UFG::SimComponent *v7; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  v6 = 18;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v7 = v3->m_Components.p[45].m_pComponent;
    if ( v7 )
      v6 = v7[3].m_NameUID;
  }
  if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumNameHash.p[v6];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *v5 = SSSymbol::as_instance(v8);
}

// File Line: 4843
// RVA: 0x4F9770
void __fastcall UFG::TSCharacter::Mthd_face_set_action(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // rsi
  UFG::SimObject *v5; // rdi
  UFG::SceneObjectProperties *v6; // rdi
  UFG::FaceActionComponent *v7; // rbx
  SSData **v8; // r8
  SSInstance *v9; // r14
  bool v10; // bp
  bool v11; // r12
  bool v12; // r13
  SSInstance *v13; // r15
  UFG::qPropertySet *v14; // rsi
  UFG::qPropertySet *v15; // rax
  UFG::qSymbol sym; // [rsp+20h] [rbp-48h]
  bool v17; // [rsp+70h] [rbp+8h]
  bool v18; // [rsp+88h] [rbp+20h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( v3 && (v3->m_Flags >> 14) & 1 )
      v5 = this->mpSimObj.m_pPointer;
    else
      v5 = 0i64;
    v6 = v5->m_pSceneObj;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_20;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v7 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( !v7 )
LABEL_20:
      v7 = UFG::FaceActionComponent::CreateFaceActionComponent(v6);
    v8 = v4->i_data.i_array_p;
    sym.mUID = (*v8)->i_data_p->i_user_data;
    v9 = v8[1]->i_data_p;
    v10 = v8[2]->i_data_p->i_user_data != 0;
    v11 = v8[3]->i_data_p->i_user_data != 0;
    v12 = v8[4]->i_data_p->i_user_data != 0;
    v13 = v8[7]->i_data_p;
    v17 = v8[5]->i_data_p->i_user_data != 0;
    v18 = v8[6]->i_data_p->i_user_data != 0;
    UFG::FaceActionComponent::LookupFaceAction(&sym);
    v14 = UFG::SceneObjectProperties::GetWritableProperties(v6);
    if ( !UFG::qPropertySet::GetParentFromName(
            v14,
            (UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID,
            DEPTH_RECURSE) )
    {
      v15 = UFG::PropertySetManager::CreateOrFindPropertySet((UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID);
      UFG::PSWrapper::AppendParentLocal(v14, v15);
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v6, (UFG::qSymbol *)&SimSym_FaceAction.mUID, &sym);
    PropertyUtils::SetRuntime<unsigned long>(v6, (UFG::qSymbol *)&SimSym_PipsRequired.mUID, v9->i_user_data);
    PropertyUtils::SetRuntime<bool>(v6, (UFG::qSymbol *)&SimSym_Hidden.mUID, v10);
    PropertyUtils::SetRuntime<bool>(v6, (UFG::qSymbol *)&SimSym_RemoveOnCompletion.mUID, v11);
    PropertyUtils::SetRuntime<bool>(v6, (UFG::qSymbol *)&SimSym_FaceActionEnabled.mUID, v12);
    PropertyUtils::SetRuntime<bool>(v6, (UFG::qSymbol *)&SimSym_MinigameSetup.mUID, v17);
    PropertyUtils::SetRuntime<bool>(v6, (UFG::qSymbol *)&SimSym_MinigameEnabled.mUID, v18);
    PropertyUtils::SetRuntime<unsigned long>(v6, (UFG::qSymbol *)&SimSym_MinigameSpeed.mUID, v13->i_user_data);
    if ( v7 )
      v7->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v7->vfptr, (unsigned int)v6);
  }
}

// File Line: 4907
// RVA: 0x4F99C0
void __fastcall UFG::TSCharacter::Mthd_face_set_purchase_item(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::TSCharacter *v4; // r15
  SSData **v5; // rdx
  SSInstance *v6; // r12
  UFG::SceneObjectProperties *v7; // r14
  UFG::qPropertySet *v8; // rbx
  UFG::qPropertySet *v9; // rax
  UFG::qPropertySet *v10; // rax
  UFG::qPropertyList *v11; // rsi
  unsigned int v12; // ebp
  unsigned int v13; // edi
  char *v14; // rax
  UFG::qPropertySet *v15; // rbx
  UFG::SimObject *v16; // rcx
  UFG::InventoryComponent *v17; // rcx
  UFG::qPropertySet *v18; // rdx
  UFG::SimObject *v19; // rcx
  UFG::FaceActionComponent *v20; // rbx
  UFG::qSymbol v; // [rsp+50h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = this;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v5 = pScope->i_data.i_array_p;
    v.mUID = (*v5)->i_data_p->i_user_data;
    v6 = v5[1]->i_data_p;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v7 = v3->m_pSceneObj;
    v8 = UFG::SceneObjectProperties::GetWritableProperties(v3->m_pSceneObj);
    if ( !UFG::qPropertySet::GetParentFromName(
            v8,
            (UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID,
            DEPTH_RECURSE) )
    {
      v9 = UFG::PropertySetManager::CreateOrFindPropertySet((UFG::qSymbol *)&SimSymX_propset_componentFaceAction.mUID);
      UFG::PSWrapper::AppendParentLocal(v8, v9);
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v7, (UFG::qSymbol *)&SimSym_SellableItem.mUID, &v);
    v10 = UFG::SceneObjectProperties::GetWritableProperties(v7);
    v11 = PropertyUtils::Get<UFG::qPropertyList>(v10, (UFG::qSymbol *)&UFG::gsymInventory.mUID, 0);
    if ( !v11 )
    {
      v11 = (UFG::qPropertyList *)UFG::qPropertyList::Create("inventory list");
      PropertyUtils::SetRuntime<UFG::qPropertyList>(v7, (UFG::qSymbol *)&UFG::gsymInventory.mUID, v11);
    }
    v12 = v11->mNumElements;
    v13 = 0;
    if ( v12 )
    {
      while ( 1 )
      {
        v14 = UFG::qPropertyList::GetValuePtr(v11, 0x1Au, v13);
        if ( v14 && *(_QWORD *)v14 )
          v15 = (UFG::qPropertySet *)&v14[*(_QWORD *)v14];
        else
          v15 = 0i64;
        if ( v15->mName.mUID == v.mUID )
          break;
        if ( ++v13 >= v12 )
          goto LABEL_17;
      }
    }
    else
    {
LABEL_17:
      v15 = UFG::qPropertySet::CreateContainedSet(&v, "item_set");
      UFG::qPropertyList::Add<UFG::qPropertySet>(v11, v15);
    }
    if ( UFG::qPropertySet::PropertyExists(v15, (UFG::qSymbol *)&UFG::gsymRange.mUID, 0) )
      UFG::qPropertySet::RemovePropertyByName(v15, (UFG::qSymbol *)&UFG::gsymRange.mUID);
    UFG::qPropertySet::Set<long>(v15, (UFG::qSymbol *)&UFG::gsymValue.mUID, v6->i_user_data);
    v16 = v4->mpSimObj.m_pPointer;
    if ( v16 && (v16->m_Flags >> 14) & 1 )
    {
      if ( !v16 || !((v16->m_Flags >> 14) & 1) )
        v16 = 0i64;
      v17 = (UFG::InventoryComponent *)v16->m_Components.p[39].m_pComponent;
      if ( v17 )
      {
        v18 = v7->mpWritableProperties;
        if ( !v18 )
          v18 = v7->mpConstProperties;
        UFG::InventoryComponent::ResetFromProperties(v17, v18);
      }
    }
    v19 = v4->mpSimObj.m_pPointer;
    if ( v19 && (v19->m_Flags >> 14) & 1 )
    {
      if ( !v19 || !((v19->m_Flags >> 14) & 1) )
        v19 = 0i64;
      v20 = (UFG::FaceActionComponent *)v19->m_Components.p[45].m_pComponent;
      if ( v20 )
      {
        v20->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v20->vfptr, (unsigned int)v7);
        UFG::FaceActionComponent::ProcessIconLogic(v20);
      }
    }
  }
}

// File Line: 4986
// RVA: 0x4F9650
void __fastcall UFG::TSCharacter::Mthd_face_get_action_min_requirement(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rbx
  unsigned int v4; // edi
  SSInstance **v5; // r14
  UFG::TSCharacter *v6; // rsi
  UFG::GameStatTracker *v7; // rax
  unsigned int v8; // eax
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rcx

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    v6 = this;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3 == UFG::GetLocalPlayer() )
    {
      v7 = UFG::GameStatTracker::Instance();
      v8 = UFG::GameStatTracker::GetFaceLevel(v7);
      *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v8);
    }
    else
    {
      v9 = v6->mpSimObj.m_pPointer;
      if ( v9 && (v9->m_Flags >> 14) & 1 )
      {
        if ( !v9 || !((v9->m_Flags >> 14) & 1) )
          v9 = 0i64;
        v10 = v9->m_Components.p[45].m_pComponent;
        if ( v10 )
          v4 = (unsigned int)v10[3].m_pSimObject;
      }
    }
    *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
  }
}

// File Line: 5012
// RVA: 0x4F9500
void __fastcall UFG::TSCharacter::Mthd_face_action_auto_completes_objective(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v3; // r8
  UFG::SimObject *v4; // rdx
  UFG::SimComponent *v5; // rbx
  UFG::qString v6; // [rsp+38h] [rbp-30h]

  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v5 = v4->m_Components.p[45].m_pComponent;
    if ( v5 )
    {
      UFG::qString::qString(&v6, *(const char **)v3->i_user_data);
      UFG::qString::Set((UFG::qString *)&v5[10].m_BoundComponentHandles.mNode.mNext, v6.mData, v6.mLength, 0i64, 0);
      UFG::qString::~qString(&v6);
    }
  }
}

// File Line: 5024
// RVA: 0x4F9730
void __fastcall UFG::TSCharacter::Mthd_face_meter_set(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
      UFG::GameStatAction::Player::ClampAndSetCombatMeter((float)SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data));
  }
}

// File Line: 5055
// RVA: 0x4E5E20
void __fastcall UFG::TSCharacter::MthdC_face_is_action_success(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // dl
  SSInstance **v5; // rbx
  UFG::FaceActionComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6) == 1;
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 5075
// RVA: 0x4E5AE0
void __fastcall UFG::TSCharacter::MthdC_face_has_been_greeted(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx
  char v5; // al

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_15;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( (v4 = v3->m_Components.p[45].m_pComponent) != 0i64
      && ((v5 = BYTE4(v4[12].m_pSimObject), v5 & 1) || BYTE4(v4[3].m_BoundComponentHandles.mNode.mPrev))
      && v5 & 2 )
    {
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
LABEL_15:
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 5095
// RVA: 0x4E6020
void __fastcall UFG::TSCharacter::MthdC_face_set_greeted(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponent *v4; // r8
  bool v5; // dl
  char v6; // al
  UFG::eFaceActionState v7; // edx
  char v8; // cl
  UFG::eFaceActionState v9; // edx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data > 0;
      BYTE4(v4[12].m_pSimObject) &= 0xFDu;
      BYTE4(v4[12].m_pSimObject) |= 2 * v5;
      v6 = BYTE4(v4[12].m_pSimObject);
      if ( v5 )
      {
        v7 = 8;
        if ( v6 & 4 )
          v7 = 4;
        UFG::FaceActionComponent::SetState((UFG::FaceActionComponent *)v4, v7);
      }
      else
      {
        if ( v6 & 1 || (v8 = 0, BYTE4(v4[3].m_BoundComponentHandles.mNode.mPrev)) )
          v8 = 1;
        v9 = 4;
        if ( v8 )
          v9 = 0;
        UFG::FaceActionComponent::SetState((UFG::FaceActionComponent *)v4, v9);
      }
    }
  }
}

// File Line: 5111
// RVA: 0x4E60E0
void __fastcall UFG::TSCharacter::MthdC_face_set_requires_greet(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[45].m_pComponent;
    if ( v5 )
      BYTE4(v5[12].m_pSimObject) ^= (BYTE4(v5[12].m_pSimObject) ^ ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
  }
}

// File Line: 5123
// RVA: 0x4E5FB0
void __fastcall UFG::TSCharacter::MthdC_face_set_auto_charge(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[45].m_pComponent;
    if ( v5 )
      BYTE4(v5[3].m_SafePointerList.mNode.mPrev) ^= (BYTE4(v5[3].m_SafePointerList.mNode.mPrev) ^ 8
                                                                                                * ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 8;
  }
}

// File Line: 5139
// RVA: 0x4E59F0
void __fastcall UFG::TSCharacter::MthdC_face_get_success_state(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::eSocialInteractionResultEnum v4; // edx
  SSInstance **v5; // rbx
  UFG::FaceActionComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6);
    }
    *v5 = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)v4);
  }
}

// File Line: 5159
// RVA: 0x4E5A60
void __fastcall UFG::TSCharacter::MthdC_face_get_success_state_as_symbol(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::eSocialInteractionResultEnum v4; // edx
  SSInstance **v5; // rbx
  UFG::FaceActionComponent *v6; // rcx
  ASymbol *v7; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6);
    }
    v7 = (ASymbol *)UFG::qSymbol::create_from_string(&result, UFG::SocialInteractionResultNames[v4]);
    *v5 = SSSymbol::as_instance(v7);
  }
}

// File Line: 5180
// RVA: 0x4F10D0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_last_conversation_result(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  int v4; // edx
  SSInstance **v5; // rbx
  UFG::SimComponent *v6; // rcx
  ASymbol *v7; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v4 = (int)v6[10].m_pSimObject;
    }
    v7 = (ASymbol *)UFG::qSymbol::create_from_string(&result, UFG::SocialInteractionResultNames[v4]);
    *v5 = SSSymbol::as_instance(v7);
  }
}

// File Line: 5200
// RVA: 0x4E5B70
void __fastcall UFG::TSCharacter::MthdC_face_is_action_failure(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  char v5; // dl
  UFG::FaceActionComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = 1;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v5 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6) == 2;
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 5220
// RVA: 0x4E5D40
void __fastcall UFG::TSCharacter::MthdC_face_is_action_minigame_success(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // dl
  SSInstance **v5; // rbx
  UFG::FaceActionComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = 0;
    v5 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v4 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6) == 3;
    }
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 5240
// RVA: 0x4E5CD0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_minigame_failure(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  char v5; // dl
  UFG::FaceActionComponent *v6; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = 1;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v6 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v6 )
        v5 = UFG::FaceActionComponent::GetFaceActionSuccessState(v6) == 4;
    }
    *v4 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 5260
// RVA: 0x4E5C50
void __fastcall UFG::TSCharacter::MthdC_face_is_action_greet_success(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_13;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 && BYTE4(v4[12].m_pSimObject) & 2 )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
LABEL_13:
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 5277
// RVA: 0x4E5BE0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_greet_failure(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx
  char v6; // al

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = 1;
    if ( v5 )
      v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(v5) == 6;
    *v4 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 5298
// RVA: 0x4E5DB0
void __fastcall UFG::TSCharacter::MthdC_face_is_action_other_failure(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx
  char v6; // al

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 && (v3->m_Flags >> 14) & 1 )
    {
      if ( !v3 || !((v3->m_Flags >> 14) & 1) )
        v3 = 0i64;
      v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    }
    else
    {
      v5 = 0i64;
    }
    v6 = 1;
    if ( v5 )
      v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(v5) == 7;
    *v4 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 5319
// RVA: 0x4E56E0
void __fastcall UFG::TSCharacter::MthdC_face_action_enable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::FaceActionComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
      UFG::FaceActionComponent::FaceActionEnable(v4, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 5333
// RVA: 0x4E6150
void __fastcall UFG::TSCharacter::MthdC_face_toggle_social_icon(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::FaceActionComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
      UFG::FaceActionComponent::ToggleGreetIcon(v4, (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0);
  }
}

// File Line: 5348
// RVA: 0x4EAFA0
void __fastcall UFG::TSCharacter::MthdC_minigame_setup(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[45].m_pComponent;
    if ( v5 )
      BYTE4(v5[3].m_BoundComponentHandles.mNode.mPrev) = (*v4->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 5362
// RVA: 0x4E5740
void __fastcall UFG::TSCharacter::MthdC_face_action_is_enabled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_13;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v5 && UFG::FaceActionComponent::IsFaceActionEnabled(v5) )
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    else
LABEL_13:
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 5377
// RVA: 0x4E58C0
void __fastcall UFG::TSCharacter::MthdC_face_action_is_setup(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3 && (v4 = v3->m_Components.p[45].m_pComponent) != 0i64 && v4[3].m_NameUID != 18 )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 5408
// RVA: 0x4E57C0
void __fastcall UFG::TSCharacter::MthdC_face_action_is_minigame_enabled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_13;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 && BYTE5(v4[3].m_BoundComponentHandles.mNode.mPrev) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
LABEL_13:
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 5424
// RVA: 0x4E5840
void __fastcall UFG::TSCharacter::MthdC_face_action_is_minigame_setup(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rcx

  if ( ppResult )
  {
    v3 = this->mpSimObj.m_pPointer;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_13;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 && BYTE4(v4[3].m_BoundComponentHandles.mNode.mPrev) )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
LABEL_13:
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 5437
// RVA: 0x4E5930
void __fastcall UFG::TSCharacter::MthdC_face_get_level(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // rbx
  SSInstance **v4; // rsi
  UFG::TSCharacter *v5; // rdi
  UFG::GameStatTracker *v6; // rax
  unsigned __int64 v7; // rdx
  UFG::SimObject *v8; // rcx
  UFG::SimComponent *v9; // rcx

  if ( ppResult )
  {
    v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    v5 = this;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    if ( v3 == UFG::GetLocalPlayer() )
    {
      v6 = UFG::GameStatTracker::Instance();
      v7 = (unsigned int)UFG::GameStatTracker::GetFaceLevel(v6);
LABEL_14:
      *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v7);
      return;
    }
    v8 = v5->mpSimObj.m_pPointer;
    if ( v8 && (v8->m_Flags >> 14) & 1 )
    {
      if ( !v8 || !((v8->m_Flags >> 14) & 1) )
        v8 = 0i64;
      v9 = v8->m_Components.p[45].m_pComponent;
      if ( v9 )
      {
        v7 = LODWORD(v9[3].m_pSimObject);
        goto LABEL_14;
      }
    }
  }
}

// File Line: 5461
// RVA: 0x4E5E90
void __fastcall UFG::TSCharacter::MthdC_face_meter_enable(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInvokedMethod *v4; // rbx
  UFG::SimComponent *v5; // rax

  v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceMeterComponent::_TypeUID);
    if ( v5 )
      LOBYTE(v5[135].m_SafePointerList.mNode.mPrev) = (*v4->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 5472
// RVA: 0x4E5F00
void __fastcall UFG::TSCharacter::MthdC_face_meter_is_enabled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( !v3 || !((v3->m_Flags >> 14) & 1) )
          v3 = 0i64;
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceMeterComponent::_TypeUID);
        if ( v5 )
          *v4 = (SSInstance *)SSBoolean::pool_new((bool)v5[135].m_SafePointerList.mNode.mPrev);
      }
    }
  }
}

// File Line: 5565
// RVA: 0x4F12F0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_is_playing(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // di
  SSInstance **v4; // rsi
  UFG::SimObject *v5; // rdx
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::Conversation *v8; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = this->mpSimObj.m_pPointer;
  if ( v5 && (v5->m_Flags >> 14) & 1 )
  {
    if ( !v5 || !((v5->m_Flags >> 14) & 1) )
      v5 = 0i64;
    v6 = (UFG::FaceActionComponent *)v5->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v8 = UFG::FaceActionComponent::GetConversationReference(v6, v7);
      if ( v8 )
        v3 = v8->m_state == 1;
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 5585
// RVA: 0x4F1420
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_play(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::FaceActionComponent *v4; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::PlayConversation(v4, v5);
    }
  }
}

// File Line: 5596
// RVA: 0x4F17B0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_stop(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::FaceActionComponent *v4; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::StopConversation(v4, v5);
    }
  }
}

// File Line: 5607
// RVA: 0x4F1CD0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_play(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::FaceActionComponent *v4; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::PlayPostInteractionConversation(v4, v5);
    }
  }
}

// File Line: 5618
// RVA: 0x4F1DE0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_stop(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::FaceActionComponent *v4; // rbx
  UFG::eSocialInteractionResultEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::StopPostInteractionConversation(v4, v5);
    }
  }
}

// File Line: 5639
// RVA: 0x4F1830
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_stop_all_conversations(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    JUMPOUT(v3->m_Components.p[45].m_pComponent, 0i64, UFG::FaceActionComponent::StopAllConversations);
  }
}

// File Line: 5644
// RVA: 0x4F1950
void __fastcall UFG::TSCharacter::MthdC_social_interaction_set_should_exit(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::SimObject *v4; // rdx
  bool v5; // di
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = pScope->i_data.i_array_p;
  sym.mUID = (*v3)->i_data_p->i_user_data;
  v4 = this->mpSimObj.m_pPointer;
  v5 = v3[1]->i_data_p->i_user_data != 0;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v6 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetShouldInteractionExit(v6, v7, v5);
    }
  }
}

// File Line: 5656
// RVA: 0x4F19E0
void __fastcall UFG::TSCharacter::MthdC_social_interaction_should_exit(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::FaceActionComponent *v5; // rbx
  bool v6; // al
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0;
  if ( v5 )
  {
    v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
    v6 = UFG::FaceActionComponent::ShouldInteractionExit(v5, v7);
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 5669
// RVA: 0x4F1690
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_should_reset(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::SimObject *v4; // rdx
  bool v5; // di
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = pScope->i_data.i_array_p;
  sym.mUID = (*v3)->i_data_p->i_user_data;
  v4 = this->mpSimObj.m_pPointer;
  v5 = v3[1]->i_data_p->i_user_data != 0;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v6 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetShouldConversationReset(v6, v7, v5);
    }
  }
}

// File Line: 5681
// RVA: 0x4F1720
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_should_reset(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::FaceActionComponent *v5; // rbx
  bool v6; // al
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0;
  if ( v5 )
  {
    v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
    v6 = UFG::FaceActionComponent::ShouldConversationReset(v5, v7);
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 5694
// RVA: 0x4F1260
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_has_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // r9
  SSInstance **v4; // rdi
  UFG::SimObject *v5; // rdx
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = this->mpSimObj.m_pPointer;
  if ( v5 && (v5->m_Flags >> 14) & 1 )
  {
    if ( !v5 || !((v5->m_Flags >> 14) & 1) )
      v5 = 0i64;
    v6 = (UFG::FaceActionComponent *)v5->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v3 = UFG::FaceActionComponent::GetConversationReference(v6, v7) != 0i64;
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 5709
// RVA: 0x4F11C0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObject *v4; // rdx
  UFG::FaceActionComponent *v5; // rbx
  UFG::eSocialInteractionResultEnum v6; // eax
  UFG::Conversation *v7; // rax
  SSInstance *v8; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v5 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    if ( v5 )
    {
      v6 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v7 = UFG::FaceActionComponent::GetConversationReference(v5, v6);
      if ( v7 )
      {
        if ( v7->m_type == eConversationType_Scripted )
        {
          v8 = (SSInstance *)v7[1].vfptr;
          if ( v8 )
            ++v8->i_ref_count;
          *v3 = v8;
        }
      }
    }
  }
}

// File Line: 5729
// RVA: 0x4F15E0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::TSCharacter *v4; // rbx
  SSInstance *v5; // rdi
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::FaceActionComponent *v9; // rbx
  UFG::eSocialInteractionResultEnum v10; // eax
  UFG::qSymbol sym; // [rsp+38h] [rbp+10h]

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  sym.mUID = (*v3)->i_data_p->i_user_data;
  v5 = v3[1]->i_data_p;
  v6 = (unsigned int)v5[1].i_class_p;
  if ( v6 )
  {
    v7 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v6);
    if ( v7 )
    {
      if ( v7 != (UFG::qBaseTreeRB *)8 )
      {
        v8 = v4->mpSimObj.m_pPointer;
        if ( v8 )
        {
          if ( (v8->m_Flags >> 14) & 1 )
          {
            if ( !v8 || !((v8->m_Flags >> 14) & 1) )
              v8 = 0i64;
            v9 = (UFG::FaceActionComponent *)v8->m_Components.p[45].m_pComponent;
            if ( v9 )
            {
              v10 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
              UFG::FaceActionComponent::SetConversationReference(v9, v10, (UFG::Conversation *)v5[2].i_user_data);
            }
          }
        }
      }
    }
  }
}

// File Line: 5746
// RVA: 0x4E5690
void __fastcall UFG::TSCharacter::MthdC_face_action_clear(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    JUMPOUT(v3->m_Components.p[45].m_pComponent, 0i64, UFG::FaceActionComponent::ClearConversationReferences);
  }
}

// File Line: 5756
// RVA: 0x4F1BB0
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_has_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // r9
  SSInstance **v4; // rdi
  UFG::SimObject *v5; // rdx
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = this->mpSimObj.m_pPointer;
  if ( v5 && (v5->m_Flags >> 14) & 1 )
  {
    if ( !v5 || !((v5->m_Flags >> 14) & 1) )
      v5 = 0i64;
    v6 = (UFG::FaceActionComponent *)v5->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v3 = UFG::FaceActionComponent::GetPostInteractionConversationReference(v6, v7) != 0i64;
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 5771
// RVA: 0x4F1B10
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_get_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::SimObject *v4; // rdx
  UFG::FaceActionComponent *v5; // rbx
  UFG::eSocialInteractionResultEnum v6; // eax
  UFG::Conversation *v7; // rax
  SSInstance *v8; // rax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v5 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    if ( v5 )
    {
      v6 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v7 = UFG::FaceActionComponent::GetPostInteractionConversationReference(v5, v6);
      if ( v7 )
      {
        if ( v7->m_type == eConversationType_Scripted )
        {
          v8 = (SSInstance *)v7[1].vfptr;
          if ( v8 )
            ++v8->i_ref_count;
          *v3 = v8;
        }
      }
    }
  }
}

// File Line: 5791
// RVA: 0x4F1D50
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_set_reference(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  UFG::SimObject *v4; // rdx
  SSInstance *v5; // rdi
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = pScope->i_data.i_array_p;
  v4 = this->mpSimObj.m_pPointer;
  sym.mUID = (*v3)->i_data_p->i_user_data;
  v5 = v3[1]->i_data_p;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( !v4 || !((v4->m_Flags >> 14) & 1) )
      v4 = 0i64;
    v6 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      UFG::FaceActionComponent::SetPostInteractionConversationReference(v6, v7, (UFG::Conversation *)v5[2].i_user_data);
    }
  }
}

// File Line: 5804
// RVA: 0x4F1390
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_is_valid(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // r9
  SSInstance **v4; // rdi
  UFG::SimObject *v5; // rdx
  hkGeometryUtils::IVertices *v6; // rbx
  int v7; // eax
  int v8; // er8
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = this->mpSimObj.m_pPointer;
  if ( v5 && (v5->m_Flags >> 14) & 1 )
  {
    if ( !v5 || !((v5->m_Flags >> 14) & 1) )
      v5 = 0i64;
    v6 = (hkGeometryUtils::IVertices *)v5->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v3 = Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(v6, v7, v8);
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 5818
// RVA: 0x4F1C40
void __fastcall UFG::TSCharacter::MthdC_social_post_interaction_dialogue_is_valid(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // r9
  SSInstance **v4; // rdi
  UFG::SimObject *v5; // rdx
  UFG::FaceActionComponent *v6; // rbx
  UFG::eSocialInteractionResultEnum v7; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = ppResult;
  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v5 = this->mpSimObj.m_pPointer;
  if ( v5 && (v5->m_Flags >> 14) & 1 )
  {
    if ( !v5 || !((v5->m_Flags >> 14) & 1) )
      v5 = 0i64;
    v6 = (UFG::FaceActionComponent *)v5->m_Components.p[45].m_pComponent;
    if ( v6 )
    {
      v7 = UFG::FaceActionComponent::LookupSocialInteraction(&sym);
      v3 = UFG::FaceActionComponent::IsPostInteractionConversationValid(v6, v7);
    }
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 5832
// RVA: 0x4F1150
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_last_played(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx
  UFG::Conversation *v6; // rax
  SSInstance *v7; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v5 )
    {
      v6 = UFG::FaceActionComponent::GetLastPlayedConversation(v5);
      if ( v6 )
      {
        if ( v6->m_type == eConversationType_Scripted )
        {
          v7 = (SSInstance *)v6[1].vfptr;
          if ( v7 )
            ++v7->i_ref_count;
          *v4 = v7;
        }
      }
    }
  }
}

// File Line: 5852
// RVA: 0x4F1590
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_last_played(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::SimComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 )
      LODWORD(v4[10].m_pSimObject) = 0;
  }
}

// File Line: 5865
// RVA: 0x4F1880
void __fastcall UFG::TSCharacter::MthdC_social_interaction_has_occurred(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx
  bool v6; // al

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0;
  if ( v5 )
    v6 = UFG::FaceActionComponent::GetFaceActionSuccessState(v5) != 0;
  *v4 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 5877
// RVA: 0x4F1A70
void __fastcall UFG::TSCharacter::MthdC_social_minigame_finished_playing(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rbx
  SSInstance **v4; // rdi
  UFG::FaceActionComponent *v5; // rbx
  bool v6; // cl

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0;
  if ( v5 )
  {
    if ( UFG::FaceActionComponent::GetFaceActionSuccessState(v5) != 3
      && UFG::FaceActionComponent::GetFaceActionSuccessState(v5) != 4 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
      return;
    }
    v6 = 1;
  }
  *v4 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 5889
// RVA: 0x4F18F0
void __fastcall UFG::TSCharacter::MthdC_social_interaction_has_succeeded(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  SSInstance **v4; // rbx
  UFG::FaceActionComponent *v5; // rcx
  bool v6; // al

  v3 = this->mpSimObj.m_pPointer;
  v4 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = 0;
  if ( v5 )
    v6 = UFG::FaceActionComponent::HasInteractionSucceeded(v5);
  *v4 = (SSInstance *)SSBoolean::pool_new(v6);
}

// File Line: 5901
// RVA: 0x4F1520
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_face_action(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::SimComponent *v4; // rbx
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p[45].m_pComponent;
    if ( v4 )
      HIDWORD(v4[10].m_pSimObject) = UFG::FaceActionComponent::LookupFaceAction(&sym);
  }
}

// File Line: 5912
// RVA: 0x4F1040
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_face_action(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  unsigned int v4; // er9
  SSInstance **v5; // rbx
  int v6; // er10
  UFG::SimComponent *v7; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  v6 = 0;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v7 = v3->m_Components.p[45].m_pComponent;
    if ( v7 )
      v6 = HIDWORD(v7[10].m_pSimObject);
  }
  if ( (UFG::gFaceActionTracksEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gFaceActionTracksEnum.m_enumLists.p)->m_enumNameHash.p[v6];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *v5 = SSSymbol::as_instance(v8);
}

// File Line: 5928
// RVA: 0x4F14A0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_set_conversation_state(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::FaceActionComponent *v4; // rbx
  UFG::eSocialConversationStateEnum v5; // eax
  UFG::qSymbol sym; // [rsp+30h] [rbp+8h]

  sym.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
    if ( v4 )
    {
      v5 = UFG::FaceActionComponent::LookupConversationState(&sym);
      UFG::FaceActionComponent::SetConversationState(v4, v5);
    }
  }
}

// File Line: 5939
// RVA: 0x4F0FC0
void __fastcall UFG::TSCharacter::MthdC_social_dialogue_get_conversation_state(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  unsigned int v4; // ebx
  SSInstance **v5; // rdi
  UFG::eSocialConversationStateEnum v6; // er9
  UFG::FaceActionComponent *v7; // rcx
  ASymbol *v8; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  v6 = 0;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v7 = (UFG::FaceActionComponent *)v3->m_Components.p[45].m_pComponent;
      if ( v7 )
        v6 = UFG::FaceActionComponent::GetConversationState(v7);
    }
  }
  if ( (UFG::gConversationStateEnum.m_enumLists.size & 0x80000000) == 0 )
    v4 = (*UFG::gConversationStateEnum.m_enumLists.p)->m_enumNameHash.p[v6];
  v8 = (ASymbol *)UFG::qSymbol::qSymbol(&result, v4);
  *v5 = SSSymbol::as_instance(v8);
}

// File Line: 5956
// RVA: 0x4F0F90
void __fastcall UFG::TSCharacter::MthdC_social_combat_fast_talk_get_succeeded(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  *ppResult = (SSInstance *)SSBoolean::pool_new((BYTE2(this->mAIScriptInterfaceComponent.m_pSimComponent[32].m_BoundComponentHandles.mNode.mPrev) >> 1) & 1);
}

// File Line: 5961
// RVA: 0x506F80
void __fastcall UFG::TSCharacter::Mthd_set_animation_lod_enabled(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  UFG::SimComponentHolder *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::AnimationLODComponent *v6; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = v3->m_Components.p;
    v5 = v4[13].m_pComponent;
    if ( v5 )
    {
      v6 = (UFG::AnimationLODComponent *)v4[13].m_pComponent;
      if ( (*pScope->i_data.i_array_p)->i_data_p->i_user_data )
      {
        ((void (__fastcall *)(UFG::AnimationLODComponent *))v5->vfptr[9].__vecDelDtor)(v6);
      }
      else
      {
        UFG::AnimationLODComponent::MakeHighLOD(v6);
        ((void (__fastcall *)(UFG::SimComponent *))v5->vfptr[8].__vecDelDtor)(v5);
      }
    }
  }
}

// File Line: 5996
// RVA: 0x4E8D00
void __fastcall UFG::TSCharacter::MthdC_grant_player_buff(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData *v3; // rcx
  UFG::ePlayerBuffEnum v4; // edx
  SSInstance *v5; // rax
  UFG::qStaticSymbol *v6; // rcx
  int v7; // eax

  v3 = *pScope->i_data.i_array_p;
  v4 = 0;
  v5 = v3->i_data_p;
  v6 = UFG::PlayerBuffEnumSymbols;
  v7 = v5->i_user_data;
  while ( v7 != v6->mUID )
  {
    ++v6;
    ++v4;
    if ( (signed __int64)v6 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_PISTOL_SERVICE_AMMO )
    {
      UFG::PlayerBuffTracker::ActivateBuff(0);
      return;
    }
  }
  UFG::PlayerBuffTracker::ActivateBuff(v4);
}

// File Line: 6006
// RVA: 0x4E9760
void __fastcall UFG::TSCharacter::MthdC_is_player_buff_active(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ePlayerBuffEnum v3; // er9
  SSInstance **v4; // rbx
  SSData *v5; // rcx
  UFG::ePlayerBuffEnum v6; // edx
  SSInstance *v7; // rax
  UFG::qStaticSymbol *v8; // rcx
  int v9; // eax
  bool v10; // al

  v3 = 0;
  v4 = ppResult;
  v5 = *pScope->i_data.i_array_p;
  v6 = 0;
  v7 = v5->i_data_p;
  v8 = UFG::PlayerBuffEnumSymbols;
  v9 = v7->i_user_data;
  while ( v9 != v8->mUID )
  {
    ++v8;
    ++v6;
    if ( (signed __int64)v8 >= (signed __int64)&UFG::qStaticSymbol_eINVENTORY_ITEM_PISTOL_SERVICE_AMMO )
      goto LABEL_6;
  }
  v3 = v6;
LABEL_6:
  v10 = UFG::PlayerBuffTracker::IsBuffActive(v3);
  *v4 = (SSInstance *)SSBoolean::pool_new(v10);
}

// File Line: 6021
// RVA: 0x511A40
char __fastcall UFG::TSCharacter::get_attack_param_real(UFG::qPropertySet *propSet, UFG::qSymbol *propName, float *value)
{
  UFG::qSymbol *v3; // rbx
  float *v4; // rdi
  int v5; // xmm6_4
  UFG::qPropertySet *v6; // rax
  char *v7; // rax
  unsigned int v8; // ecx

  v3 = propName;
  v4 = value;
  v5 = 0;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         propSet,
         (UFG::qSymbol *)&object_physical_character_stats_BaseAttackParameters::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( !v6 )
    goto LABEL_5;
  v7 = UFG::qPropertySet::GetMemImagePtr(v6);
  if ( !v7 )
    goto LABEL_5;
  v8 = v3->mUID;
  if ( v3->mUID == gsymMaxDistanceToChooseCloseAttack.mUID )
  {
    v5 = *(_DWORD *)v7;
LABEL_5:
    *(_DWORD *)v4 = v5;
    return 1;
  }
  if ( v8 == gsymExitDistanceForCloseAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 1);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxDistanceToChooseMidAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 2);
    goto LABEL_5;
  }
  if ( v8 == gsymExitDistanceForMidAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 3);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxDistanceToUseCloseAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 4);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxDistanceToUseMidAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 5);
    goto LABEL_5;
  }
  if ( v8 == gsymMinRunningAttackDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 7);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxRunningAttackDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 8);
    goto LABEL_5;
  }
  if ( v8 == gsymRunningAttackExitDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 9);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunisticMeleeAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)v7 + 10);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunisticMeleeAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)v7 + 11);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunisticMeleeExitDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 12);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityMeleeAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)v7 + 13);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityMeleeAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)v7 + 14);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityMeleeExitDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 15);
    goto LABEL_5;
  }
  if ( v8 == gsymMinTimeBeforeOpportunityMeleeAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 16);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxTimeBeforeOpportunityMeleeAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 17);
    goto LABEL_5;
  }
  if ( v8 == gsymMinForOpportunityMeleeAttackTimeout.mUID )
  {
    v5 = *((_DWORD *)v7 + 18);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxForOpportunityMeleeAttackTimeout.mUID )
  {
    v5 = *((_DWORD *)v7 + 19);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityRangedAttackDistanceVSPlayer.mUID )
  {
    v5 = *((_DWORD *)v7 + 20);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityRangedAttackDistanceVSAI.mUID )
  {
    v5 = *((_DWORD *)v7 + 21);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxOpportunityRangedExitDistance.mUID )
  {
    v5 = *((_DWORD *)v7 + 22);
    goto LABEL_5;
  }
  if ( v8 == gsymMinTimeBeforeOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 23);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxTimeBeforeOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 24);
    goto LABEL_5;
  }
  if ( v8 == gsymMinTimeBeforeNextOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 25);
    goto LABEL_5;
  }
  if ( v8 == gsymMaxTimeBeforeNextOpportunityRangedAttack.mUID )
  {
    v5 = *((_DWORD *)v7 + 26);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 27);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 28);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 29);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 30);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeVSHumanAsEnemyMobBattle.mUID )
  {
    v5 = *((_DWORD *)v7 + 31);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeVSHumanAsEnemyMobBattle.mUID )
  {
    v5 = *((_DWORD *)v7 + 32);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 33);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 34);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 35);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 36);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 37);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 38);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 39);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 40);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 41);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 42);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 43);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 44);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 45);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 46);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 47);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 48);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 49);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 50);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 51);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersDownedVSHumanAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 52);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 53);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 54);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 55);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 56);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 57);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 58);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 59);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 60);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 61);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 62);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 63);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 64);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 65);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 66);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 67);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 68);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 69);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 70);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 71);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 72);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 73);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 74);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 75);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersDownedVSAIAsEnemy.mUID )
  {
    v5 = *((_DWORD *)v7 + 76);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 77);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 78);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 79);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 80);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinMeleeDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 81);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxMeleeDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 82);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 83);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 84);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 85);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 86);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 87);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 88);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 89);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 90);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 91);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 92);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinRangedInCoverDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 93);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxRangedInCoverDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 94);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMinDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 95);
    goto LABEL_5;
  }
  if ( v8 == gsymInitialAttackTimeMaxDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 96);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 97);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 98);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMinDirectFollowersDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 99);
    goto LABEL_5;
  }
  if ( v8 == gsymAttackTimeMaxDirectFollowersDownedVSAIAsAlly.mUID )
  {
    v5 = *((_DWORD *)v7 + 100);
    goto LABEL_5;
  }
  return 0;
}

// File Line: 6142
// RVA: 0x4FB840
void __fastcall UFG::TSCharacter::Mthd_get_attack_param_real(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  SSData *v4; // rdx
  UFG::SimObject *v5; // rax
  UFG::qSymbol *v6; // r9
  UFG::SceneObjectProperties *v7; // rdx
  UFG::qPropertySet *v8; // rcx
  float value; // [rsp+30h] [rbp+8h]

  v3 = ppResult;
  v4 = *pScope->i_data.i_array_p;
  v5 = this->mpSimObj.m_pPointer;
  value = 0.0;
  v6 = (UFG::qSymbol *)v4->i_data_p;
  v7 = v5->m_pSceneObj;
  v8 = v7->mpWritableProperties;
  if ( !v8 )
    v8 = v7->mpConstProperties;
  UFG::TSCharacter::get_attack_param_real(v8, v6 + 8, &value);
  *v3 = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(value));
}

// File Line: 6155
// RVA: 0x4FB7B0
void __fastcall UFG::TSCharacter::Mthd_get_attack_param_int(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v3; // ebx
  SSInstance **v4; // rsi
  SSInstance *v5; // rdi
  UFG::SceneObjectProperties *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertySet *v8; // rax
  object_physical_character_stats_BaseAttackParameters *v9; // rax

  v3 = 0;
  v4 = ppResult;
  v5 = (*pScope->i_data.i_array_p)->i_data_p;
  v6 = this->mpSimObj.m_pPointer->m_pSceneObj;
  v7 = v6->mpWritableProperties;
  if ( !v7 )
    v7 = v6->mpConstProperties;
  v8 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v7,
         (UFG::qSymbol *)&object_physical_character_stats_BaseAttackParameters::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v8 )
  {
    v9 = (object_physical_character_stats_BaseAttackParameters *)UFG::qPropertySet::GetMemImagePtr(v8);
    if ( v9 )
    {
      if ( LODWORD(v5->i_user_data) == gsymChanceToUseMidAttack.mUID )
        v3 = v9->ChanceToUseMidAttack;
    }
  }
  *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
}

// File Line: 6178
// RVA: 0x504DE0
void __fastcall UFG::TSCharacter::Mthd_money_adjust(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatAction::Money::Exchange(
    0i64,
    *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64) + 32i64),
    (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 6187
// RVA: 0x504E10
void __fastcall UFG::TSCharacter::Mthd_money_get(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // eax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, Money);
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 6196
// RVA: 0x504E50
void __fastcall UFG::TSCharacter::Mthd_money_set(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v3; // rbx
  UFG::GameStatTracker *v4; // rax

  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, Money, v3->i_user_data);
}

// File Line: 6203
// RVA: 0x4FCC50
void __fastcall UFG::TSCharacter::Mthd_get_faction(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::TSCharacter *v4; // rdi
  UFG::GameStatTracker *v5; // rax
  UFG::SimObject *v6; // rdx
  UFG::FactionInterface *v7; // rsi
  UFG::eFactionClassEnum v8; // eax
  UFG::qStaticSymbol *v9; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = this;
    v5 = UFG::FactionInterface::Get();
    v6 = v4->mpSimObj.m_pPointer;
    v7 = &v5->mFactionInterface;
    if ( !v6 || !((v6->m_Flags >> 14) & 1) )
      v6 = 0i64;
    v8 = (unsigned int)UFG::FactionInterface::GetFaction(&v5->mFactionInterface, v6);
    v9 = UFG::FactionInterface::MapFactionToSymbol(v7, v8);
    *v3 = SSSymbol::as_instance((ASymbol *)v9);
  }
}

// File Line: 6214
// RVA: 0x507F80
void __fastcall UFG::TSCharacter::Mthd_set_faction(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  UFG::TSCharacter *v4; // rdi
  SSInstance *v5; // rbx
  UFG::GameStatTracker *v6; // rax
  UFG::SimObject *v7; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = this;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    v5 = (*pScope->i_data.i_array_p)->i_data_p;
    v6 = UFG::FactionInterface::Get();
    v7 = v4->mpSimObj.m_pPointer;
    if ( !v7 || !((v7->m_Flags >> 14) & 1) )
      v7 = 0i64;
    UFG::FactionInterface::SetFaction(&v6->mFactionInterface, v7, (UFG::qSymbol *)&v5->i_user_data);
  }
}

// File Line: 6231
// RVA: 0x4F41E0
void __fastcall UFG::TSCharacter::Mthd_add_follower(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::SimObject *v7; // rcx
  UFG::ActiveAIEntityComponent *v8; // rax

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( !v5 )
    goto LABEL_6;
  v6 = v5->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
          v6,
          *v3,
          ppResult) )
  {
    if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    {
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v5 = 0i64;
  }
LABEL_7:
  if ( v4->mAIScriptInterfaceComponent.m_pSimComponent && v5 )
  {
    v7 = *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count;
    if ( v7 )
    {
      v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                             v7,
                                             UFG::ActiveAIEntityComponent::_TypeUID);
      UFG::AIScriptInterfaceComponent::AddFollower(
        (UFG::AIScriptInterfaceComponent *)v4->mAIScriptInterfaceComponent.m_pSimComponent,
        v8);
    }
  }
}

// File Line: 6245
// RVA: 0x4F93B0
void __fastcall UFG::TSCharacter::Mthd_equip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rax
  UFG::TSCharacter *v4; // rsi
  SSActor *v5; // rbx
  SSClass *v6; // rdi
  UFG::SimObject *v7; // rcx
  UFG::SimObject *v8; // rdx

  v3 = pScope->i_data.i_array_p;
  v4 = this;
  v5 = (SSActor *)(*v3)->i_data_p;
  if ( !v5 )
    goto LABEL_6;
  v6 = v5->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSData *, SSInstance **))v6->vfptr->is_actor_class)(
          v6,
          *v3,
          ppResult) )
  {
    if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    {
      v5 = SSActor::find((ASymbol *)&v5->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v5 = 0i64;
  }
LABEL_7:
  v7 = v4->mpSimObj.m_pPointer;
  if ( v7 )
  {
    if ( (v7->m_Flags >> 14) & 1 )
    {
      if ( v5 )
      {
        v8 = *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count;
        if ( v8 )
        {
          if ( !v7 || !((v7->m_Flags >> 14) & 1) )
            v7 = 0i64;
          UFG::InventoryComponent::Equip(v7, v8);
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

  v0 = UFG::qStringHashUpper32("Grip R Hand", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symGripRHand, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symGripRHand__);
}

// File Line: 6264
// RVA: 0x50DE60
void __fastcall UFG::TSCharacter::Mthd_unequip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // r14
  UFG::SimObject *v4; // r8
  SSData **v5; // rdx
  SSInstance *v6; // rcx
  bool v7; // r9
  char v8; // dl
  UFG::TargetingSystemBaseComponent *v9; // r13
  __int64 v10; // r15
  __int64 v11; // r12
  signed __int64 v12; // rcx
  UFG::TargetingSimObject *v13; // rax
  UFG::SimObjectProp *v14; // rbx
  bool v15; // al
  unsigned __int16 v16; // cx
  UFG::SimObjectWeaponPropertiesComponent *v17; // rax
  UFG::CharacterAnimationComponent *v18; // rdi
  UFG::SimObjectCharacter *v19; // rax
  UFG::SimComponent *v20; // rax
  Creature *v21; // rsi
  __int64 v22; // rdi
  int v23; // ebp
  signed int v24; // eax
  UFG::InventoryComponent *v25; // rcx
  UFG::SimObjectCharacter *v26; // rax
  __int64 v27; // r9
  UFG::CompositeDrawableComponent *v28; // rcx
  bool v29; // zf
  __int64 v30; // [rsp+20h] [rbp-98h]
  bool v31; // [rsp+40h] [rbp-78h]
  signed __int64 v32; // [rsp+48h] [rbp-70h]
  UFG::eTargetTypeEnum eTargetType; // [rsp+58h] [rbp-60h]
  int v34; // [rsp+5Ch] [rbp-5Ch]
  int v35; // [rsp+60h] [rbp-58h]
  char v36; // [rsp+C0h] [rbp+8h]
  bool v37; // [rsp+D8h] [rbp+20h]

  v3 = this;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 )
  {
    if ( (v4->m_Flags >> 14) & 1 )
    {
      v5 = pScope->i_data.i_array_p;
      v31 = (*v5)->i_data_p->i_user_data != 0;
      v6 = v5[1]->i_data_p;
      v7 = v6->i_user_data != 0;
      v37 = v6->i_user_data != 0;
      v8 = 0;
      v36 = 0;
      if ( v4 )
      {
        if ( (v4->m_Flags >> 14) & 1 )
        {
          if ( !v4 || !((v4->m_Flags >> 14) & 1) )
            v4 = 0i64;
          v9 = (UFG::TargetingSystemBaseComponent *)v4->m_Components.p[20].m_pComponent;
          if ( v9 )
          {
            eTargetType = 42;
            v34 = 17;
            v35 = 43;
            if ( !(_S10_9 & 1) )
            {
              _S10_9 |= 1u;
              UFG::qSymbolUC::create_from_string(BoneName, "Bip01 R Thigh");
              UFG::qSymbolUC::create_from_string(&stru_14240D774, "Bip01 R Prop");
              UFG::qSymbolUC::create_from_string(&stru_14240D778, "Bip01 L Thigh");
              atexit(UFG::TSCharacter::Mthd_unequip_::_8_::_dynamic_atexit_destructor_for__BoneName__);
              v8 = 0;
              v7 = v37;
            }
            v10 = 0i64;
            v32 = 3i64;
            do
            {
              v11 = *(unsigned int *)((char *)&eTargetType + v10 * 4);
              v12 = (unsigned __int8)v9->m_pTargetingMap->m_Map.p[v11];
              v13 = v9->m_pTargets;
              v14 = (UFG::SimObjectProp *)v13[v12].m_pTarget.m_pPointer;
              v15 = v14 && v13[v12].m_bLock;
              if ( v14 && v15 )
              {
                if ( v7
                  && !v8
                  && ((v16 = v14->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) : (v17 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v17 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v14))) : (v17 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID))) : (v17 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v14->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)),
                      v17 && v17->mWeaponTypeInfo->mFireModes[v17->mFireMode]->mStowable) )
                {
                  v8 = 1;
                  v36 = 1;
                }
                else
                {
                  if ( UFG::TSCharacter::GetSimObjectCharacter(v3) )
                  {
                    v19 = UFG::TSCharacter::GetSimObjectCharacter(v3);
                    v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)&v19->vfptr);
                  }
                  else
                  {
                    v18 = 0i64;
                  }
                  v20 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v14->vfptr,
                          UFG::CharacterAnimationComponent::_TypeUID);
                  if ( v18 )
                    v21 = v18->mCreature;
                  else
                    v21 = 0i64;
                  if ( v20 )
                    v22 = *(_QWORD *)&v20[2].m_TypeUID;
                  else
                    v22 = 0i64;
                  if ( v21 && v22 )
                  {
                    v23 = v21->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                                        v21->mPose.mRigHandle.mUFGSkeleton,
                                                                        BoneName[v10].mUID) : -1;
                    v24 = *(_QWORD *)(v22 + 440) ? (unsigned int)Skeleton::GetBoneID(
                                                                   *(Skeleton **)(v22 + 480),
                                                                   UFG::symGripRHand.mUID) : -1;
                    if ( v23 >= 0 && v24 >= 0 )
                    {
                      if ( UFG::TSCharacter::GetSimObjectCharacter(v3) )
                      {
                        v25 = (UFG::InventoryComponent *)UFG::TSCharacter::GetSimObjectCharacter(v3)->m_Components.p[39].m_pComponent;
                        if ( v25 )
                        {
                          UFG::InventoryComponent::RemoveObjectFromInventory(
                            v25,
                            (UFG::SimObject *)&v14->vfptr,
                            v10 * 4);
                          v26 = UFG::TSCharacter::GetSimObjectCharacter(v3);
                          Creature::RemoveAttachment(
                            v21,
                            (UFG::SimObject *)&v26->vfptr,
                            v23,
                            (UFG::SimObject *)&v14->vfptr);
                          LODWORD(v30) = 0;
                          LOBYTE(v27) = 1;
                          ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, __int64, const char *, _QWORD, _QWORD))v9->vfptr[14].__vecDelDtor)(
                            v9,
                            (unsigned int)v11,
                            0i64,
                            v27,
                            v30,
                            "TSCharacter::Mthd_unequip",
                            0i64,
                            0i64);
                          UFG::TargetingSystemBaseComponent::ClearTarget(v9, (UFG::eTargetTypeEnum)v11);
                          if ( UFG::TSCharacter::GetSimObjectCharacter(v3) )
                          {
                            v28 = (UFG::CompositeDrawableComponent *)UFG::TSCharacter::GetSimObjectCharacter(v3)->m_Components.p[14].m_pComponent;
                            if ( v28 )
                              UFG::CompositeDrawableComponent::SetIsHidden(v28, 0);
                          }
                          if ( (UFG::SimObjectCharacter *)v3->mpSimObj.m_pPointer == LocalPlayer && (_DWORD)v11 == 17 )
                            UFG::GameStatAction::Inventory::UnEquip(0);
                          if ( v31 )
                            UFG::Simulation::DestroySimObject(&UFG::gSim, (UFG::SimObject *)&v14->vfptr);
                        }
                      }
                    }
                  }
                  v8 = v36;
                }
              }
              ++v10;
              v29 = v32-- == 1;
              v7 = v37;
            }
            while ( !v29 );
          }
        }
      }
    }
  }
}     }
              ++v10;
              v29 = v32-- == 1;
              v

// File Line: 6382
// RVA: 0x50C3C0
void __fastcall UFG::TSCharacter::Mthd_stow_equipped_firearm(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rdx
  UFG::InventoryComponent *v4; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    v4 = (UFG::InventoryComponent *)v3->m_Components.p[39].m_pComponent;
    if ( v4 )
      UFG::InventoryComponent::Stow(v4, 0, eINVENTORY_EQUIP_SLOT_STOWED_1H);
  }
}

// File Line: 6401
// RVA: 0x4F4460
void __usercall UFG::TSCharacter::Mthd_add_to_inventory(UFG::TSCharacter *this@<rcx>, SSInvokedMethod *pScope@<rdx>, SSInstance **ppResult@<r8>, __int64 a4@<r15>)
{
  UFG::TSCharacter *v4; // rbx
  SSData **v5; // r8
  int v6; // edi
  UFG::SimObject *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  UFG::SimObject *v10; // rcx
  UFG::InventoryComponent *v11; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v12; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v13; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v4 = this;
  v5 = pScope->i_data.i_array_p;
  v6 = v5[1]->i_data_p->i_user_data;
  v7 = this->mpSimObj.m_pPointer;
  if ( v7 && (v7->m_Flags >> 14) & 1 && (*v5)->i_data_p != (SSInstance *)-32i64 )
  {
    v8 = UFG::qSymbol::create_from_string(&result, *(const char **)(*v5)->i_data_p->i_user_data);
    pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
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
      v9 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mPrev = v9;
      pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
      UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    if ( pTrackEnumBinding.m_EnumValue )
    {
      v10 = v4->mpSimObj.m_pPointer;
      if ( v10 )
      {
        if ( (v10->m_Flags >> 14) & 1 )
        {
          if ( !v10 || !((v10->m_Flags >> 14) & 1) )
            v10 = 0i64;
          v11 = (UFG::InventoryComponent *)v10->m_Components.p[39].m_pComponent;
          if ( v11 )
            UFG::InventoryComponent::AddQuantity(v11, (UFG::eInventoryItemEnum)pTrackEnumBinding.m_EnumValue, v6, a4);
        }
      }
    }
    v12 = pTrackEnumBinding.mPrev;
    v13 = pTrackEnumBinding.mNext;
    pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
    v13->mPrev = v12;
  }
}

// File Line: 6441
// RVA: 0x50B1D0
void __fastcall UFG::TSCharacter::Mthd_set_unlimited_ammo(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 && v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[39].m_pComponent;
    if ( v5 )
      BYTE1(v5[14].m_pSimObject) = (*v4->i_data.i_array_p)->i_data_p->i_user_data != 0;
  }
}

// File Line: 6462
// RVA: 0x500420
void __fastcall UFG::TSCharacter::Mthd_inventory_create_and_equip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rbx
  UFG::SimObject *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::SimObject *v6; // rdx

  v3 = this;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 )
  {
    if ( (v4->m_Flags >> 14) & 1 )
    {
      v5 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      if ( v5 )
      {
        v6 = v3->mpSimObj.m_pPointer;
        if ( !v6 || !((v6->m_Flags >> 14) & 1) )
          v6 = 0i64;
        UFG::SimObjectUtility::CreateAndAttachProp(v5, v6, 0);
      }
    }
  }
}

// File Line: 6485
// RVA: 0x500660
void __fastcall UFG::TSCharacter::Mthd_inventory_slot_unequip(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInvokedMethod *v4; // rdi
  UFG::TSCharacter *v5; // rbx
  UFG::eInventoryEquipSlot v6; // er9
  UFG::SimObject *v7; // rdx
  UFG::InventoryComponent *v8; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  v5 = this;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v6 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                           &UFG::gInventoryEquipSlotsTracksEnum,
                           (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v7 = v5->mpSimObj.m_pPointer;
      if ( v7 )
      {
        if ( (v7->m_Flags >> 14) & 1 )
        {
          if ( !v7 || !((v7->m_Flags >> 14) & 1) )
            v7 = 0i64;
          v8 = (UFG::InventoryComponent *)v7->m_Components.p[39].m_pComponent;
          if ( v8 )
            UFG::InventoryComponent::UnEquip(
              v8,
              v6,
              *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
        }
      }
    }
  }
}

// File Line: 6509
// RVA: 0x5005B0
void __fastcall UFG::TSCharacter::Mthd_inventory_slot_set_can_drop(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  SSInvokedMethod *v4; // rdi
  UFG::TSCharacter *v5; // rbx
  UFG::eInventoryEquipSlot v6; // er9
  UFG::SimObject *v7; // rdx
  UFG::InventoryComponent *v8; // rcx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  v5 = this;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v6 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                           &UFG::gInventoryEquipSlotsTracksEnum,
                           (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v7 = v5->mpSimObj.m_pPointer;
      if ( v7 )
      {
        if ( (v7->m_Flags >> 14) & 1 )
        {
          if ( !v7 || !((v7->m_Flags >> 14) & 1) )
            v7 = 0i64;
          v8 = (UFG::InventoryComponent *)v7->m_Components.p[39].m_pComponent;
          if ( v8 )
            UFG::InventoryComponent::SetCanDrop(
              v8,
              v6,
              *(_QWORD *)(*(_QWORD *)(*((_QWORD *)v4->i_data.i_array_p + 1) + 8i64) + 32i64) != 0i64);
        }
      }
    }
  }
}

// File Line: 6532
// RVA: 0x500490
void __fastcall UFG::TSCharacter::Mthd_inventory_is_equipped(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rax
  bool v4; // bl
  SSInstance **v5; // rdi
  SSInvokedMethod *v6; // rbp
  UFG::TSCharacter *v7; // rsi
  int v8; // er14
  UFG::eInventoryEquipSlot v9; // eax
  int v10; // eax
  UFG::SimObject *v11; // rdx
  UFG::TargetingSystemPedPlayerComponent *v12; // r8
  UFG::SimObject *v13; // rcx
  UFG::SimComponent *v14; // rax
  int v15; // eax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  v6 = pScope;
  v7 = this;
  if ( v3 )
  {
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v8 = TracksEnum<unsigned long>::GetEnumFromSymbol(
             &UFG::gInventoryItemTracksEnum,
             (UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      v9 = (unsigned int)TracksEnum<unsigned long>::GetEnumFromSymbol(
                           &UFG::gInventoryEquipSlotsTracksEnum,
                           (UFG::qSymbol *)(*(_QWORD *)(*((_QWORD *)v6->i_data.i_array_p + 1) + 8i64) + 32i64));
      v10 = UFG::InventoryComponent::GetSlotTarget(v9);
      v11 = v7->mpSimObj.m_pPointer;
      if ( v11 )
      {
        if ( (v11->m_Flags >> 14) & 1 )
        {
          v12 = (UFG::TargetingSystemPedPlayerComponent *)v11->m_Components.p[eTARGET_TYPE_EQUIPPED_GLASSES].m_pComponent;
          if ( v12 )
          {
            v13 = v12->m_pTargets[(unsigned __int8)v12->m_pTargetingMap->m_Map.p[v10]].m_pTarget.m_pPointer;
            if ( v13 )
            {
              v14 = UFG::SimObject::GetComponentOfType(v13, UFG::InventoryItemComponent::_TypeUID);
              if ( v14 )
              {
                v15 = (int)v14[1].m_pSimObject;
                v4 = v15 && v8 == v15;
              }
            }
          }
        }
      }
    }
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 6572
// RVA: 0x4FFD00
void __fastcall UFG::TSCharacter::Mthd_group_is_leader(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  char v4; // dl
  SSInstance **v5; // rbx

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = UFG::GroupComponent::IsLeader(v3);
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 6592
// RVA: 0x4FFB90
void __fastcall UFG::TSCharacter::Mthd_group_is_follower(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  bool v4; // dl
  SSInstance **v5; // rbx

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = UFG::GroupComponent::IsFollower(v3);
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 6612
// RVA: 0x4FFBF0
void __fastcall UFG::TSCharacter::Mthd_group_is_group_member(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  char v4; // dl
  SSInstance **v5; // rbx

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v4 = UFG::GroupComponent::IsGroupMember(v3);
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 6632
// RVA: 0x4FFC50
void __fastcall UFG::TSCharacter::Mthd_group_is_in_my_group(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx
  char v4; // si
  SSInstance **v5; // rdi
  SSInvokedMethod *v6; // rbp
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v7; // rbx
  UFG::TSActor *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v10; // rax

  v3 = this->mpSimObj.m_pPointer;
  v4 = 0;
  v5 = ppResult;
  v6 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v7 = UFG::GroupComponent::GetGroupComponent(v3);
    if ( v7 )
    {
      v8 = UFG::TSActor::GetArgByNameOrInstance((SSInvokedContextBase *)&v6->vfptr, 0);
      if ( v8 )
      {
        v9 = v8->mpSimObj.m_pPointer;
        if ( v9 )
        {
          v10 = UFG::GroupComponent::GetGroupComponent(v9);
          if ( v10 )
            v4 = UFG::GroupComponent::IsInGroup((UFG::GroupComponent *)v7, (UFG::GroupComponent *)v10);
        }
      }
    }
  }
  if ( v5 )
    *v5 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 6676
// RVA: 0x4FF8D0
void __fastcall UFG::TSCharacter::Mthd_group_get_leader(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v5; // rax
  UFG::GroupComponent *v6; // rax
  UFG::SimObject *v7; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 )
      {
        if ( !v4 || !((v4->m_Flags >> 14) & 1) )
          v4 = 0i64;
        v5 = UFG::GroupComponent::GetGroupComponent(v4);
        if ( v5 )
        {
          v6 = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)v5);
          if ( v6 )
          {
            v7 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v6);
            *v3 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v7);
          }
        }
      }
    }
  }
}

// File Line: 6707
// RVA: 0x4FF950
void __fastcall UFG::TSCharacter::Mthd_group_get_members(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // r15
  UFG::SimObject *v4; // rcx
  unsigned int v5; // ebx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v6; // rbp
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v7; // rax
  APArray<SSActor,SSActor,ACompareAddress<SSActor> > *v8; // rdi
  UFG::GroupComponent *v9; // rax
  UFG::GroupComponent *v10; // r14
  UFG::SimObject *v11; // rax
  UFG::TSActorComponent *v12; // rax
  UFG::TSActor *v13; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v14; // rax
  UFG::GroupComponent *v15; // rsi
  UFG::SimObject *v16; // rax
  UFG::TSActorComponent *v17; // rax
  UFG::TSActor *v18; // rax
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v19; // rsi
  UFG::SimObject *v20; // rax
  UFG::TSActorComponent *v21; // rax
  UFG::TSActor *v22; // rax
  __int64 v23; // rax
  ARefCountMix<SSInstance> **v24; // rbx
  unsigned __int64 i; // rsi

  if ( ppResult )
  {
    v3 = ppResult;
    *ppResult = SSBrain::c_nil_p;
    v4 = this->mpSimObj.m_pPointer;
    if ( v4 )
    {
      if ( (v4->m_Flags >> 14) & 1 )
      {
        v5 = 0;
        if ( !v4 || !((v4->m_Flags >> 14) & 1) )
          v4 = 0i64;
        v6 = UFG::GroupComponent::GetGroupComponent(v4);
        if ( v6 )
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
          v9 = UFG::GroupComponent::GetLeader((UFG::GroupComponent *)v6);
          v10 = v9;
          if ( v9 )
          {
            if ( UFG::GroupComponent::GetSimObjectPtr(v9) )
            {
              v11 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v10);
              v12 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v11, UFG::TSActorComponent::_TypeUID);
              if ( v12 )
              {
                v13 = UFG::TSActorComponent::GetActor(v12);
                APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, (SSActor *)&v13->vfptr);
              }
            }
            if ( Scaleform::Render::Hairliner::GetMeshVertexCount(v10) )
            {
              do
              {
                v14 = UFG::GroupComponent::GetFollower(v10, v5);
                v15 = (UFG::GroupComponent *)v14;
                if ( v6 != v14 )
                {
                  if ( UFG::GroupComponent::GetSimObjectPtr((UFG::GroupComponent *)v14) )
                  {
                    v16 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr(v15);
                    v17 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                     v16,
                                                     UFG::TSActorComponent::_TypeUID);
                    if ( v17 )
                    {
                      v18 = UFG::TSActorComponent::GetActor(v17);
                      APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, (SSActor *)&v18->vfptr);
                    }
                  }
                }
                ++v5;
              }
              while ( v5 < Scaleform::Render::Hairliner::GetMeshVertexCount(v10) );
            }
          }
          else if ( UFG::GroupComponent::IsLeader((UFG::GroupComponent *)v6)
                 && Scaleform::Render::Hairliner::GetMeshVertexCount((UFG::GroupComponent *)v6) )
          {
            do
            {
              v19 = UFG::GroupComponent::GetFollower((UFG::GroupComponent *)v6, v5);
              if ( UFG::GroupComponent::GetSimObjectPtr((UFG::GroupComponent *)v19) )
              {
                v20 = (UFG::SimObject *)UFG::GroupComponent::GetSimObjectPtr((UFG::GroupComponent *)v19);
                v21 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v20, UFG::TSActorComponent::_TypeUID);
                if ( v21 )
                {
                  v22 = UFG::TSActorComponent::GetActor(v21);
                  APArray<SSActor,SSActor,ACompareAddress<SSActor>>::append(v8, (SSActor *)&v22->vfptr);
                }
              }
              ++v5;
            }
            while ( v5 < Scaleform::Render::Hairliner::GetMeshVertexCount((UFG::GroupComponent *)v6) );
          }
          v23 = v8->i_count;
          if ( (_DWORD)v23 )
          {
            v24 = (ARefCountMix<SSInstance> **)v8->i_array_p;
            for ( i = (unsigned __int64)&v24[v23]; (unsigned __int64)v24 < i; ++v24 )
              UFG::PersistentData::MapFloat::Iterator::Next(*v24 + 4);
          }
          *v3 = SSList::as_instance((SSList *)v8);
        }
      }
    }
  }
}

// File Line: 6774
// RVA: 0x4FFD60
void __fastcall UFG::TSCharacter::Mthd_group_leave(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // rcx

  v3 = this->mpSimObj.m_pPointer;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    UFG::GroupComponent::LeaveGroup(v3);
  }
}

// File Line: 6789
// RVA: 0x507870
void __fastcall UFG::TSCharacter::Mthd_set_can_wander(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v3; // rax
  UFG::SimObject *v4; // rdx

  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = this->mpSimObj.m_pPointer;
  if ( v4 && (v4->m_Flags >> 14) & 1 )
  {
    if ( v4 && (v4->m_Flags >> 14) & 1 )
    {
      if ( !v4 || !((v4->m_Flags >> 14) & 1) )
        v4 = 0i64;
      BYTE5(v4->m_Components.p[22].m_pComponent[20].m_BoundComponentHandles.mNode.mPrev) = v3->i_user_data != 0;
    }
    else
    {
      MEMORY[0x535] = v3->i_user_data != 0;
    }
  }
}

// File Line: 6801
// RVA: 0x504B80
void __fastcall UFG::TSCharacter::Mthd_lock_freerun_mode(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // r8
  SSData *v4; // rax
  const char ***v5; // r12
  const char ***v6; // r13
  unsigned int v7; // esi
  char v8; // r14
  const char **v9; // rdi
  unsigned int v10; // er15
  char v11; // bp
  unsigned int v12; // ebx
  UFG::SimComponent *v13; // rax
  UFG::TSCharacter *v14; // [rsp+50h] [rbp+8h]

  v14 = this;
  v3 = pScope->i_data.i_array_p;
  v4 = v3[1];
  v5 = (const char ***)&(*v3)->i_data_p->i_user_data;
  v6 = (const char ***)&v4->i_data_p->i_user_data;
  if ( this->mActiveAIEntityComponent.m_pSimComponent
    && (*v3)->i_data_p != (SSInstance *)-32i64
    && v4->i_data_p != (SSInstance *)-32i64 )
  {
    v7 = 0;
    v8 = 0;
    v9 = UFG::gParkourTypeNames;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    do
    {
      if ( !(unsigned int)UFG::qStringCompareInsensitive(**v5, *v9, -1) )
      {
        v7 = v12;
        v8 = 1;
      }
      if ( !(unsigned int)UFG::qStringCompareInsensitive(**v6, *v9, -1) )
      {
        v10 = v12;
        v11 = 1;
      }
      ++v12;
      ++v9;
    }
    while ( v12 < 3 );
    if ( v8 )
    {
      if ( v11 )
      {
        v13 = v14->mActiveAIEntityComponent.m_pSimComponent;
        *((_BYTE *)&v13[65].m_SimObjIndex + 2) = 1;
        v13[65].m_NameUID = v7;
        *(_DWORD *)&v13[65].m_Flags = v10;
      }
    }
  }
}

// File Line: 6850
// RVA: 0x50E3C0
void __fastcall UFG::TSCharacter::Mthd_unlock_freerun_mode(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  v3 = this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    *((_BYTE *)&v3[65].m_SimObjIndex + 2) = 0;
}

// File Line: 6860
// RVA: 0x50B2B0
void __fastcall UFG::TSCharacter::Mthd_set_vault_success_rate(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ActiveAIEntityComponent *v3; // rcx

  v3 = (UFG::ActiveAIEntityComponent *)this->mActiveAIEntityComponent.m_pSimComponent;
  if ( v3 )
    UFG::ActiveAIEntityComponent::SetParkourSuccessRate(
      v3,
      *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 6872
// RVA: 0x50B240
void __fastcall UFG::TSCharacter::Mthd_set_usable_for_cop_system(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r8
  SSInvokedMethod *v4; // r9
  UFG::SimComponent *v5; // rdx

  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = v3->m_Components.p[17].m_pComponent;
    if ( v5 )
      LOBYTE(v5[7].m_Flags) ^= (LOBYTE(v5[7].m_Flags) ^ 2 * ((*v4->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 2;
  }
}

// File Line: 6921
// RVA: 0x504060
void __fastcall UFG::TSCharacter::Mthd_list_gather_characters(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *v3; // r13
  SSData **v4; // r9
  float v5; // xmm6_4
  int v6; // er15
  int v7; // er12
  int v8; // edi
  int v9; // ebx
  int v10; // esi
  int v11; // ebp
  SSInstance *v12; // rcx
  int v13; // er14
  float v14; // xmm1_4
  float v15; // xmm2_4
  unsigned int v16; // er13
  SSActor **v17; // r8
  SSActorClass *v18; // rax
  float v19; // xmm6_4
  SSActor **v20; // rcx
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rsi
  __int64 *v23; // r14
  unsigned __int64 v24; // rbp
  SSActor **v25; // rbx
  __int64 v26; // rax
  UFG::TransformNodeComponent *v27; // rax
  int v28; // eax
  SSActor **v29; // rax
  __int64 v30; // rdx
  signed __int64 v31; // rax
  signed __int64 v32; // rcx
  UFG::SimObjectCVBase *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::SimObjectCharacterPropertiesComponent *v35; // rax
  bool v36; // al
  UFG::TSCharacter *v37; // rcx
  const char **v38; // rcx
  bool v39; // al
  bool v40; // al
  UFG::SimComponent *v41; // rax
  UFG::qPropertySet *v42; // rax
  char v43; // al
  bool v44; // cl
  signed __int64 v45; // rdx
  unsigned int v46; // ecx
  unsigned int v47; // edx
  UFG::qBaseTreeRB *v48; // rax
  SSList *v49; // rax
  SSList *v50; // rbx
  __int64 i; // rsi
  SSInstance *v52; // r14
  __int64 v53; // rdi
  SSInstance **v54; // rbp
  unsigned __int64 v55; // rax
  SSActor **v56; // rax
  __int64 v57; // rax
  ARefCountMix<SSInstance> **v58; // rdi
  unsigned __int64 j; // rsi
  int v60; // [rsp+20h] [rbp-B8h]
  unsigned int v61; // [rsp+20h] [rbp-B8h]
  unsigned int v62; // [rsp+20h] [rbp-B8h]
  SSActor **Src; // [rsp+28h] [rbp-B0h]
  const char **Srca; // [rsp+28h] [rbp-B0h]
  char *Srcb; // [rsp+28h] [rbp-B0h]
  int v66; // [rsp+30h] [rbp-A8h]
  unsigned int v67; // [rsp+30h] [rbp-A8h]
  SSActor **ptr; // [rsp+40h] [rbp-98h]
  int v69; // [rsp+50h] [rbp-88h]
  signed __int64 v70; // [rsp+50h] [rbp-88h]
  UFG::qVector3 pos; // [rsp+58h] [rbp-80h]
  SSActor *v72; // [rsp+68h] [rbp-70h]
  const char ***v73; // [rsp+70h] [rbp-68h]
  __int64 v74; // [rsp+78h] [rbp-60h]
  UFG::TSCharacter *v75; // [rsp+E0h] [rbp+8h]
  float *v76; // [rsp+E8h] [rbp+10h]
  SSInstance **v77; // [rsp+F0h] [rbp+18h]
  int v78; // [rsp+F8h] [rbp+20h]
  int v79; // [rsp+F8h] [rbp+20h]

  v77 = ppResult;
  v75 = this;
  v74 = -2i64;
  v3 = this->mpSimObj.m_pPointer;
  v4 = pScope->i_data.i_array_p;
  v5 = *(float *)&(*v4)->i_data_p->i_user_data;
  v6 = v4[1]->i_data_p->i_user_data;
  v7 = v4[2]->i_data_p->i_user_data;
  v8 = v4[3]->i_data_p->i_user_data;
  v73 = (const char ***)&v4[4]->i_data_p->i_user_data;
  v9 = v4[5]->i_data_p->i_user_data;
  v78 = v4[5]->i_data_p->i_user_data;
  v10 = v4[6]->i_data_p->i_user_data;
  v66 = v4[6]->i_data_p->i_user_data;
  v11 = v4[7]->i_data_p->i_user_data;
  v60 = v4[7]->i_data_p->i_user_data;
  v12 = v4[8]->i_data_p;
  v13 = v12->i_user_data;
  v69 = v12->i_user_data;
  if ( v3 )
    v3 = (UFG::SimObject *)v3->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
  v14 = *((float *)v3[1].mNode.mChild + 1);
  v15 = *(float *)&v3[1].mNode.mChild[1];
  pos.x = *(float *)v3[1].mNode.mChild;
  pos.y = v14;
  pos.z = v15;
  v16 = 0;
  v17 = 0i64;
  ptr = 0i64;
  v18 = UFG::SkookumMgr::mspCharacterClass;
  if ( !UFG::SkookumMgr::mspCharacterClass )
    v18 = SSBrain::c_physical_actor_class_p;
  v19 = v5 * v5;
  v20 = v18->i_instances.i_array_p;
  v21 = (unsigned __int64)&v20[v18->i_instances.i_count];
  if ( (unsigned __int64)v20 < v21 )
  {
    LODWORD(v22) = 0;
    v23 = (__int64 *)v20;
    v24 = v21;
    v25 = 0i64;
    do
    {
      v26 = *v23;
      v72 = (SSActor *)v26;
      v27 = *(UFG::TransformNodeComponent **)(v26 + 152);
      v76 = (float *)v27;
      if ( v27 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v27);
        if ( (float)((float)((float)((float)(pos.y - v76[45]) * (float)(pos.y - v76[45]))
                           + (float)((float)(pos.x - v76[44]) * (float)(pos.x - v76[44])))
                   + (float)((float)(pos.z - v76[46]) * (float)(pos.z - v76[46]))) <= v19 )
        {
          v28 = v16 + 1;
          if ( (unsigned int)v22 < v16 + 1 )
          {
            Src = v25;
            if ( v16 == -1 )
              LODWORD(v22) = 0;
            else
              v22 = (unsigned __int64)AMemory::c_req_byte_size_func(8 * (v16 & 0xFFFFFFFC) + 32) >> 3;
            v29 = APArrayBase<SSActor>::alloc_array(v22);
            v25 = v29;
            ptr = v29;
            memmove(v29, Src, 8i64 * v16);
            AMemory::c_free_func(Src);
            v28 = v16 + 1;
          }
          v25[v16] = v72;
          v16 = v28;
        }
      }
      ++v23;
    }
    while ( (unsigned __int64)v23 < v24 );
    v9 = v78;
    v10 = v66;
    v11 = v60;
    v13 = v69;
    v17 = ptr;
  }
  v30 = v16 - 1;
  v79 = v30;
  if ( (signed int)v30 >= 0 )
  {
    v31 = (signed __int64)&v17[(signed int)v30];
    v70 = (signed __int64)&v17[(signed int)v30];
    while ( *(UFG::TSCharacter **)v31 != v75 )
    {
      v33 = *(UFG::SimObjectCVBase **)(*(_QWORD *)v31 + 208i64);
      if ( v6 != qSymbol_dontcare.mUID && v33 )
      {
        v34 = v33->m_Flags;
        if ( (v34 >> 14) & 1 )
        {
          v35 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v33);
        }
        else if ( (v34 & 0x8000u) == 0 )
        {
          if ( (v34 >> 13) & 1 )
            v35 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  (UFG::SimObjectGame *)&v33->vfptr,
                                                                  UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
          else
            v35 = (UFG::SimObjectCharacterPropertiesComponent *)((v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     (UFG::SimObjectGame *)&v33->vfptr,
                                                                                     UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v33->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
        }
        else
        {
          v35 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v33);
        }
        if ( v35 )
        {
          v36 = v35->m_symFactionClass.mUID == v7;
          if ( v6 == qSymbol_exclude.mUID )
            v36 = v36 == 0;
          if ( !v36 )
            goto LABEL_84;
        }
      }
      v37 = v75;
      if ( v8 != qSymbol_dontcare.mUID && v75->mActiveAIEntityComponent.m_pSimComponent )
      {
        v61 = 0;
        v38 = UFG::AIObjectiveNames;
        Srca = UFG::AIObjectiveNames;
        while ( (unsigned int)UFG::qStringCompareInsensitive(**v73, *v38, -1) )
        {
          ++v61;
          v38 = Srca + 1;
          ++Srca;
          if ( v61 >= 0x24 )
          {
            v39 = 0;
            goto LABEL_44;
          }
        }
        v39 = 1;
LABEL_44:
        if ( v8 == qSymbol_exclude.mUID )
          v39 = v39 == 0;
        if ( !v39 )
          goto LABEL_84;
        v37 = v75;
      }
      if ( v9 != qSymbol_dontcare.mUID )
      {
        if ( v9 == qSymbol_alive.mUID )
        {
          v40 = UFG::IsKnockedOut(v37->mpSimObj.m_pPointer) == 0;
        }
        else
        {
          if ( v9 != qSymbol_dead.mUID )
            goto LABEL_84;
          v40 = UFG::IsKnockedOut(v37->mpSimObj.m_pPointer);
        }
        if ( !v40 )
          goto LABEL_84;
      }
      if ( v11 != qSymbol_dontcare.mUID )
      {
        v41 = (UFG::SimComponent *)UFG::TSCharacter::GetSimObjectCharacter(v75);
        if ( v41 )
        {
          v41 = (UFG::SimComponent *)UFG::TSCharacter::GetSimObjectCharacter(v75);
          if ( v41 )
            v41 = UFG::TSCharacter::GetSimObjectCharacter(v75)->m_Components.p[44].m_pComponent;
          LOBYTE(v41) = v41 != 0i64;
        }
        if ( v11 != qSymbol_invehicle.mUID )
          LOBYTE(v41) = (_BYTE)v41 == 0;
        if ( !(_BYTE)v41 )
          goto LABEL_84;
      }
      if ( v13 != qSymbol_dontcare.mUID )
      {
        v42 = PropertyUtils::Get<bool>(
                v75->mpSimObj.m_pPointer->m_pSceneObj,
                (UFG::qSymbol *)&qSymbol_ScenarioControl.mUID);
        if ( v42 )
        {
          v43 = v42->mFlags;
        }
        else
        {
          PropertyUtils::SetRuntime<bool>(
            v75->mpSimObj.m_pPointer->m_pSceneObj,
            (UFG::qSymbol *)&qSymbol_ScenarioControl.mUID,
            0);
          v43 = 0;
        }
        if ( v13 == qSymbol_notscenariocontrol.mUID )
          v43 = v43 == 0;
        if ( !v43 )
          goto LABEL_84;
      }
      if ( v10 != qSymbol_dontcare.mUID )
      {
        v44 = 0;
        v62 = UFG::TSGameSlice::msInteriorTriggerData.size;
        v67 = 0;
        if ( UFG::TSGameSlice::msInteriorTriggerData.size )
        {
          v45 = 0i64;
          Srcb = 0i64;
          v46 = UFG::TSGameSlice::msInteriorTriggerData.size;
          do
          {
            v47 = *(unsigned int *)((char *)&UFG::TSGameSlice::msInteriorTriggerData.p->mTriggerName.mUID + v45);
            if ( v47 )
            {
              v48 = UFG::qBaseTreeRB::Get(&UFG::TriggerRegion::msTriggerRegions.mTree, v47);
              if ( v48
                && v48 != (UFG::qBaseTreeRB *)112
                && UFG::RegionComponent::IsHitPoint((UFG::RegionComponent *)v48[1].mNULL.mParent, &pos) )
              {
                v44 = 1;
                goto LABEL_81;
              }
              v46 = v62;
            }
            ++v67;
            v45 = (signed __int64)(Srcb + 168);
            Srcb += 168;
          }
          while ( v67 < v46 );
          v44 = 0;
        }
LABEL_81:
        if ( v10 == qSymbol_outdoors.mUID )
          v44 = v44 == 0;
        if ( !v44 )
        {
LABEL_84:
          --v16;
          LODWORD(v30) = v79;
          v32 = (signed __int64)&ptr[v79];
          goto LABEL_85;
        }
      }
LABEL_86:
      v30 = (unsigned int)(v79 - 1);
      v79 = v30;
      v31 = v70 - 8;
      v70 -= 8i64;
      if ( (signed int)v30 < 0 )
        goto LABEL_87;
      v17 = ptr;
    }
    --v16;
    v32 = (signed __int64)&v17[v30];
LABEL_85:
    memmove((void *)v32, (const void *)(v32 + 8), 8i64 * (v16 - (unsigned int)v30));
    goto LABEL_86;
  }
LABEL_87:
  v49 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList");
  v50 = v49;
  if ( v49 )
  {
    v49->i_items.i_count = 0;
    v49->i_items.i_array_p = 0i64;
    v49->i_items.i_size = 0;
    v49->i_items.i_array_p = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  else
  {
    v50 = 0i64;
  }
  for ( i = (signed int)(v16 - 1); i >= 0; --i )
  {
    v52 = (SSInstance *)&ptr[i]->vfptr;
    v53 = v50->i_items.i_count;
    if ( v50->i_items.i_size < (unsigned int)(v53 + 1) )
    {
      v54 = v50->i_items.i_array_p;
      if ( (_DWORD)v53 == -1 )
        LODWORD(v55) = 0;
      else
        v55 = (unsigned __int64)AMemory::c_req_byte_size_func(32 * (((unsigned int)v53 >> 2) + 1)) >> 3;
      v50->i_items.i_size = v55;
      v56 = APArrayBase<SSActor>::alloc_array(v55);
      v50->i_items.i_array_p = (SSInstance **)v56;
      memmove(v56, v54, 8 * v53);
      AMemory::c_free_func(v54);
    }
    v50->i_items.i_array_p[v53] = v52;
    ++v50->i_items.i_count;
  }
  v57 = v50->i_items.i_count;
  if ( (_DWORD)v57 )
  {
    v58 = (ARefCountMix<SSInstance> **)v50->i_items.i_array_p;
    for ( j = (unsigned __int64)&v58[v57]; (unsigned __int64)v58 < j; ++v58 )
      UFG::PersistentData::MapFloat::Iterator::Next(*v58 + 4);
  }
  *v77 = SSList::as_instance(v50);
  AMemory::c_free_func(ptr);
}3] = v52;
    ++v50->i_items.i_count;
  }
  v57 = v50->i_items.i_count;
  if ( (_DWORD)v57 )
  {
    v58 = (ARefCountMix<SSInstance> **)v50->i_items.i_array_p;
    for ( j = (unsigned __int64)&v58[v57]; (unsigned __int64)v58 < j; ++v58 )
      UFG::PersistentData::MapFloat::Iterator:

// File Line: 7121
// RVA: 0x504B30
void __fastcall UFG::TSPlayer::Mthd_load_mission_item(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v3; // rcx
  UFG::qSymbol *v4; // rdi
  bool v5; // bl
  UFG::StoreFrontTracker *v6; // rax

  v3 = pScope->i_data.i_array_p;
  v4 = (UFG::qSymbol *)(*v3)->i_data_p;
  v5 = v3[1]->i_data_p->i_user_data != 0;
  v6 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::LoadMissionItem(v6, v4 + 8, v5);
}

// File Line: 7130
// RVA: 0x503EA0
void __fastcall UFG::TSPlayer::Mthd_is_wearing_preset_outfit(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::GameStatTracker *v4; // rax
  UFG::PersistentData::ID *v5; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::GameStatTracker::Instance();
    v5 = UFG::GameStatTracker::GetStat(v4, CurrentOutfit);
    *v3 = (SSInstance *)SSBoolean::pool_new(v5->mValue.mUID != -1);
  }
}

// File Line: 7139
// RVA: 0x4FDAA0
void __fastcall UFG::TSPlayer::Mthd_get_outfit_name(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::GameStatTracker *v4; // rax
  ASymbol sym; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::GameStatTracker::Instance();
    sym.i_uid = UFG::GameStatTracker::GetStat(v4, CurrentOutfit)->mValue.mUID;
    *v3 = SSSymbol::as_instance(&sym);
  }
}

// File Line: 7150
// RVA: 0x50E3A0
void __fastcall UFG::TSPlayer::Mthd_unload_mission_items(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::StoreFrontTracker *v3; // rax

  v3 = UFG::StoreFrontTracker::Instance();
  UFG::StoreFrontTracker::ResetEquipment(v3);
}

// File Line: 7158
// RVA: 0x4FCCC0
void __fastcall UFG::TSPlayer::Mthd_get_fashion_value(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  UFG::StoreFrontTracker *v4; // rax
  unsigned int v5; // eax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::StoreFrontTracker::Instance();
    v5 = UFG::StoreFrontTracker::GetClothingFashionValueTotal(v4);
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, v5);
  }
}

// File Line: 7169
// RVA: 0x4FCD00
void __fastcall UFG::TSPlayer::Mthd_get_fashion_value_for_article(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  __int64 v4; // rbx
  UFG::StoreFrontTracker *v5; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
    v5 = UFG::StoreFrontTracker::Instance();
    *v3 = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)v5->mClothingFashionValue[v4]);
  }
}

// File Line: 7187
// RVA: 0x4FC290
void __fastcall UFG::TSPlayer::Mthd_get_clothing_item(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rdi
  UFG::GameStat::IDStat v4; // ebx
  UFG::GameStatTracker *v5; // rax
  ASymbol *v6; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = UFG::GameStat::GetIDStatEnum((UFG::qSymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data, 1);
    v5 = UFG::GameStatTracker::Instance();
    v6 = (ASymbol *)UFG::GameStatTracker::GetStat(v5, v4);
    *v3 = SSSymbol::as_instance(v6);
  }
}

// File Line: 7199
// RVA: 0x501AF0
void __fastcall UFG::TSPlayer::Mthd_is_in_store(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  hkpNullContactMgrFactory *v4; // rax
  hkpCollidable *v5; // rdx
  hkpCollidable *v6; // r8
  hkpCollisionInput *v7; // r9
  hkpNullContactMgr *v8; // rax

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = (hkpNullContactMgrFactory *)UFG::StoreFrontTracker::Instance();
    v8 = hkpNullContactMgrFactory::createContactMgr(v4, v5, v6, v7);
    *v3 = (SSInstance *)SSBoolean::pool_new(LODWORD(v8[1].vfptr) != 0);
  }
}

// File Line: 7208
// RVA: 0x501260
void __fastcall UFG::TSPlayer::Mthd_is_combat_meter_activated(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  SSInstance **v4; // rbx
  UFG::SimComponent *v5; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = ppResult;
    if ( v3 )
    {
      if ( (v3->m_Flags >> 14) & 1 )
      {
        if ( !v3 || !((v3->m_Flags >> 14) & 1) )
          v3 = 0i64;
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::FaceMeterComponent::_TypeUID);
        if ( v5 )
          *v4 = (SSInstance *)SSBoolean::pool_new(BYTE1(v5[135].m_SafePointerList.mNode.mPrev));
      }
    }
  }
}

// File Line: 7221
// RVA: 0x502410
void __fastcall UFG::TSPlayer::Mthd_is_inside_safe_area(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v3; // rbx
  SSInvokedMethod *v4; // rdi
  UFG::CopSystem *v5; // rax
  char v6; // al
  bool pIsFullyInside; // [rsp+40h] [rbp+18h]

  if ( ppResult )
  {
    v3 = ppResult;
    v4 = pScope;
    pIsFullyInside = 0;
    v5 = UFG::CopSystem::Instance();
    v6 = (unsigned __int64)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v5, &pIsFullyInside);
    (*v4->i_data.i_array_p)->i_data_p->i_user_data = pIsFullyInside;
    *v3 = (SSInstance *)SSBoolean::pool_new(v6);
  }
}

// File Line: 7235
// RVA: 0x4FDB40
void __fastcall UFG::TSPlayer::Mthd_get_owned_vehicle(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *v3; // rcx
  UFG::SimObject *v4; // rbx
  SSInstance **v5; // rdi
  UFG::VehicleOwnershipComponent *v6; // rax
  UFG::SimObject *v7; // rax

  if ( ppResult )
  {
    v3 = (UFG::SimObjectGame *)this->mpSimObj.m_pPointer;
    v4 = 0i64;
    v5 = ppResult;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      goto LABEL_14;
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v6 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v3,
                                             UFG::VehicleOwnershipComponent::_TypeUID);
    if ( v6
      && (v7 = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v6), (v4 = v7) != 0i64)
      && UFG::SimObjectUtility::IsClassType(v7, (UFG::qSymbol *)&qSymbol_Boat_15.mUID) )
    {
      *v5 = SSBrain::c_nil_p;
    }
    else
    {
LABEL_14:
      *v5 = (SSInstance *)UFG::TSActor::SkookumObjFromSimObj(v4);
    }
  }
}

// File Line: 7251
// RVA: 0x505A10
void __fastcall UFG::TSPlayer::Mthd_override_reticle_size(UFG::TSPlayer *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectCharacter *v3; // r8
  SSInvokedMethod *v4; // rbx
  UFG::AimingPlayerComponent *v5; // r8
  SSData **v6; // rdx

  v3 = (UFG::SimObjectCharacter *)this->mpSimObj.m_pPointer;
  v4 = pScope;
  if ( v3 && (v3->m_Flags >> 14) & 1 )
  {
    if ( !v3 || !((v3->m_Flags >> 14) & 1) )
      v3 = 0i64;
    v5 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v3);
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v4->i_data.i_array_p;
  if ( (*v6)->i_data_p->i_user_data )
    v5->m_fOverrideReticleSize = *(float *)&v6[1]->i_data_p->i_user_data;
  else
    v5->m_fOverrideReticleSize = -1.0;
}

// File Line: 7272
// RVA: 0x508B70
void __fastcall UFG::TSCharacter::Mthd_set_is_out_of_fight(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // r8

  v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
  if ( v3 )
    LOBYTE(v3[32].m_BoundComponentHandles.mNode.mPrev) ^= (LOBYTE(v3[32].m_BoundComponentHandles.mNode.mPrev) ^ 32 * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 0x20;
}

// File Line: 7285
// RVA: 0x4FD440
void __fastcall UFG::TSCharacter::Mthd_get_is_out_of_fight(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimComponent *v3; // rax

  if ( ppResult )
  {
    v3 = this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( v3 && (_QWORD)v3[32].m_BoundComponentHandles.mNode.mPrev & 0x20 )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 7298
// RVA: 0x5028E0
void __fastcall UFG::TSCharacter::Mthd_is_out_of_fight(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::AIScriptInterfaceComponent *v3; // rax

  if ( ppResult )
  {
    v3 = (UFG::AIScriptInterfaceComponent *)this->mAIScriptInterfaceComponent.m_pSimComponent;
    if ( v3 )
      *ppResult = (SSInstance *)SSBoolean::pool_new((*((_BYTE *)v3 + 2096) >> 5) & 1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
  }
}

// File Line: 7325
// RVA: 0x501A30
void __fastcall UFG::TSCharacter::Mthd_is_in_fight(UFG::TSCharacter *this, SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSCharacter *v3; // rbx
  SSInstance **v4; // rdi
  UFG::SimComponent *v5; // rax

  if ( ppResult )
  {
    v3 = this;
    v4 = ppResult;
    if ( UFG::IsKnockedOut(this->mpSimObj.m_pPointer)
      || (v5 = v3->mAIScriptInterfaceComponent.m_pSimComponent) == 0i64
      || (_QWORD)v5[32].m_BoundComponentHandles.mNode.mPrev & 0x20 )
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(0);
    }
    else
    {
      *v4 = (SSInstance *)SSBoolean::pool_new(1);
    }
  }
}

// File Line: 7341
// RVA: 0x4D4FF0
void UFG::TSPlayer::BindAtomics(void)
{
  SSActorClass *v0; // rax
  SSActorClass *v1; // rcx
  SSActorClass *v2; // rcx
  SSActorClass *v3; // rcx
  SSActorClass *v4; // rcx
  SSActorClass *v5; // rcx
  SSActorClass *v6; // rcx
  SSActorClass *v7; // rcx
  SSActorClass *v8; // rcx
  SSActorClass *v9; // rcx
  SSActorClass *v10; // rcx
  __m128i v11; // [rsp+20h] [rbp-10h]

  v0 = (SSActorClass *)SSBrain::get_class("Player");
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_load_mission_item;
  v11.m128i_i32[2] = 0;
  _mm_store_si128(&v11, v11);
  UFG::SkookumMgr::mspPlayerClass = v0;
  SSClass::register_method_mthd(
    (SSClass *)&v0->vfptr,
    "equip_mission_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v1 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_is_wearing_preset_outfit;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v1->vfptr,
    "is_wearing_preset_outfit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v2 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_get_outfit_name;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v2->vfptr,
    "get_outfit_name",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v3 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_unload_mission_items;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v3->vfptr,
    "reset_equipment",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v4 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_get_fashion_value;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v4->vfptr,
    "get_fashion_value",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v5 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_get_fashion_value_for_article;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v5->vfptr,
    "get_fashion_value_for_article",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v6 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_get_clothing_item;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v6->vfptr,
    "get_clothing_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_is_in_store;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspPlayerClass->vfptr,
    "is_in_store",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v7 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_is_combat_meter_activated;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v7->vfptr,
    "is_combat_meter_activated",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v8 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_is_inside_safe_area;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v8->vfptr,
    "is_inside_safe_area",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v9 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_get_owned_vehicle;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v9->vfptr,
    "get_owned_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
  v10 = UFG::SkookumMgr::mspPlayerClass;
  v11.m128i_i32[2] = 0;
  v11.m128i_i64[0] = (__int64)UFG::TSPlayer::Mthd_override_reticle_size;
  _mm_store_si128(&v11, v11);
  SSClass::register_method_mthd(
    (SSClass *)&v10->vfptr,
    "override_reticle_size",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v11,
    0);
}

// File Line: 7368
// RVA: 0x4CF1E0
void UFG::TSCharacter::BindAtomics(void)
{
  SSActorClass *v0; // rax
  SSActorClass *v1; // rcx
  SSActorClass *v2; // rcx
  SSActorClass *v3; // rcx
  SSActorClass *v4; // rcx
  SSActorClass *v5; // rcx
  SSActorClass *v6; // rcx
  SSActorClass *v7; // rcx
  SSActorClass *v8; // rcx
  SSActorClass *v9; // rcx
  SSActorClass *v10; // rcx
  SSActorClass *v11; // rcx
  SSActorClass *v12; // rcx
  SSActorClass *v13; // rcx
  SSActorClass *v14; // rcx
  SSActorClass *v15; // rcx
  SSActorClass *v16; // rcx
  SSActorClass *v17; // rcx
  SSActorClass *v18; // rcx
  SSActorClass *v19; // rcx
  SSActorClass *v20; // rcx
  SSActorClass *v21; // rcx
  SSActorClass *v22; // rcx
  SSActorClass *v23; // rcx
  SSActorClass *v24; // rcx
  SSActorClass *v25; // rcx
  SSActorClass *v26; // rcx
  SSActorClass *v27; // rcx
  SSActorClass *v28; // rcx
  SSActorClass *v29; // rcx
  SSActorClass *v30; // rcx
  SSActorClass *v31; // rcx
  SSActorClass *v32; // rcx
  SSActorClass *v33; // rcx
  SSActorClass *v34; // rcx
  SSActorClass *v35; // rcx
  SSActorClass *v36; // rcx
  SSActorClass *v37; // rcx
  SSActorClass *v38; // rcx
  SSActorClass *v39; // rcx
  SSActorClass *v40; // rcx
  SSActorClass *v41; // rcx
  SSActorClass *v42; // rcx
  SSActorClass *v43; // rcx
  SSActorClass *v44; // rcx
  SSActorClass *v45; // rcx
  SSActorClass *v46; // rcx
  SSActorClass *v47; // rcx
  SSActorClass *v48; // rcx
  SSActorClass *v49; // rcx
  SSActorClass *v50; // rcx
  SSActorClass *v51; // rcx
  SSActorClass *v52; // rcx
  SSActorClass *v53; // rcx
  SSActorClass *v54; // rcx
  SSActorClass *v55; // rcx
  SSActorClass *v56; // rcx
  SSActorClass *v57; // rcx
  SSActorClass *v58; // rcx
  SSActorClass *v59; // rcx
  SSActorClass *v60; // rcx
  SSActorClass *v61; // rcx
  SSActorClass *v62; // rcx
  SSActorClass *v63; // rcx
  SSActorClass *v64; // rcx
  SSActorClass *v65; // rcx
  SSActorClass *v66; // rcx
  SSActorClass *v67; // rcx
  SSActorClass *v68; // rcx
  SSActorClass *v69; // rcx
  SSActorClass *v70; // rcx
  SSActorClass *v71; // rcx
  SSActorClass *v72; // rcx
  SSActorClass *v73; // rcx
  SSActorClass *v74; // rcx
  SSActorClass *v75; // rcx
  SSActorClass *v76; // rcx
  SSActorClass *v77; // rcx
  SSActorClass *v78; // rcx
  SSActorClass *v79; // rcx
  SSActorClass *v80; // rcx
  SSActorClass *v81; // rcx
  SSActorClass *v82; // rcx
  SSActorClass *v83; // rcx
  SSActorClass *v84; // rcx
  SSActorClass *v85; // rcx
  SSActorClass *v86; // rcx
  SSActorClass *v87; // rcx
  SSActorClass *v88; // rcx
  SSActorClass *v89; // rcx
  SSActorClass *v90; // rcx
  SSActorClass *v91; // rcx
  SSActorClass *v92; // rcx
  SSActorClass *v93; // rcx
  SSActorClass *v94; // rcx
  SSActorClass *v95; // rcx
  SSActorClass *v96; // rcx
  SSActorClass *v97; // rcx
  SSActorClass *v98; // rcx
  SSActorClass *v99; // rcx
  SSActorClass *v100; // rcx
  SSActorClass *v101; // rcx
  SSActorClass *v102; // rcx
  SSActorClass *v103; // rcx
  SSActorClass *v104; // rcx
  SSActorClass *v105; // rcx
  SSActorClass *v106; // rcx
  SSActorClass *v107; // rcx
  SSActorClass *v108; // rcx
  SSActorClass *v109; // rcx
  SSActorClass *v110; // rcx
  SSActorClass *v111; // rcx
  SSActorClass *v112; // rcx
  SSActorClass *v113; // rcx
  SSActorClass *v114; // rcx
  SSActorClass *v115; // rcx
  SSActorClass *v116; // rcx
  SSActorClass *v117; // rcx
  SSActorClass *v118; // rcx
  SSActorClass *v119; // rcx
  SSActorClass *v120; // rcx
  SSActorClass *v121; // rcx
  SSActorClass *v122; // rcx
  SSActorClass *v123; // rcx
  SSActorClass *v124; // rcx
  SSActorClass *v125; // rcx
  SSActorClass *v126; // rcx
  SSActorClass *v127; // rcx
  SSActorClass *v128; // rcx
  SSActorClass *v129; // rcx
  SSActorClass *v130; // rcx
  SSActorClass *v131; // rcx
  SSActorClass *v132; // rcx
  SSActorClass *v133; // rcx
  SSActorClass *v134; // rcx
  SSActorClass *v135; // rcx
  SSActorClass *v136; // rcx
  SSActorClass *v137; // rcx
  SSActorClass *v138; // rcx
  SSActorClass *v139; // rcx
  SSActorClass *v140; // rcx
  SSActorClass *v141; // rcx
  SSActorClass *v142; // rcx
  SSActorClass *v143; // rcx
  SSActorClass *v144; // rcx
  SSActorClass *v145; // rcx
  SSActorClass *v146; // rcx
  SSActorClass *v147; // rcx
  SSActorClass *v148; // rcx
  SSActorClass *v149; // rcx
  SSActorClass *v150; // rcx
  SSActorClass *v151; // rcx
  SSActorClass *v152; // rcx
  SSActorClass *v153; // rcx
  SSActorClass *v154; // rcx
  SSActorClass *v155; // rcx
  SSActorClass *v156; // rcx
  SSActorClass *v157; // rcx
  SSActorClass *v158; // rcx
  SSActorClass *v159; // rcx
  SSActorClass *v160; // rcx
  SSActorClass *v161; // rcx
  SSActorClass *v162; // rcx
  SSActorClass *v163; // rcx
  SSActorClass *v164; // rcx
  SSActorClass *v165; // rcx
  SSActorClass *v166; // rcx
  SSActorClass *v167; // rcx
  SSActorClass *v168; // rcx
  SSActorClass *v169; // rcx
  SSActorClass *v170; // rcx
  SSActorClass *v171; // rcx
  SSActorClass *v172; // rcx
  SSActorClass *v173; // rcx
  SSActorClass *v174; // rcx
  SSActorClass *v175; // rcx
  SSActorClass *v176; // rcx
  SSActorClass *v177; // rcx
  SSActorClass *v178; // rcx
  SSActorClass *v179; // rcx
  SSActorClass *v180; // rcx
  SSActorClass *v181; // rcx
  SSActorClass *v182; // rcx
  SSActorClass *v183; // rcx
  SSActorClass *v184; // rcx
  SSActorClass *v185; // rcx
  SSActorClass *v186; // rcx
  SSActorClass *v187; // rcx
  SSActorClass *v188; // rcx
  SSActorClass *v189; // rcx
  SSActorClass *v190; // rcx
  SSActorClass *v191; // rcx
  SSActorClass *v192; // rcx
  SSActorClass *v193; // rcx
  SSActorClass *v194; // rcx
  SSActorClass *v195; // rcx
  SSActorClass *v196; // rcx
  SSActorClass *v197; // rcx
  SSActorClass *v198; // rcx
  SSActorClass *v199; // rcx
  SSActorClass *v200; // rcx
  SSActorClass *v201; // rcx
  SSActorClass *v202; // rcx
  SSActorClass *v203; // rcx
  SSActorClass *v204; // rcx
  SSActorClass *v205; // rcx
  SSActorClass *v206; // rcx
  SSActorClass *v207; // rcx
  SSActorClass *v208; // rcx
  SSActorClass *v209; // rcx
  SSActorClass *v210; // rcx
  SSActorClass *v211; // rcx
  SSActorClass *v212; // rcx
  SSActorClass *v213; // rcx
  SSActorClass *v214; // rcx
  SSActorClass *v215; // rcx
  SSActorClass *v216; // rcx
  SSActorClass *v217; // rcx
  SSActorClass *v218; // rcx
  SSActorClass *v219; // rcx
  SSActorClass *v220; // rcx
  SSActorClass *v221; // rcx
  SSActorClass *v222; // rcx
  SSActorClass *v223; // rcx
  SSActorClass *v224; // rcx
  SSActorClass *v225; // rcx
  SSActorClass *v226; // rcx
  SSActorClass *v227; // rcx
  SSActorClass *v228; // rcx
  SSActorClass *v229; // rcx
  SSActorClass *v230; // rcx
  SSActorClass *v231; // rcx
  SSActorClass *v232; // rcx
  SSActorClass *v233; // rcx
  SSActorClass *v234; // rcx
  SSActorClass *v235; // rcx
  SSActorClass *v236; // rcx
  SSActorClass *v237; // rcx
  SSActorClass *v238; // rcx
  SSActorClass *v239; // rcx
  SSActorClass *v240; // rcx
  SSActorClass *v241; // rcx
  SSActorClass *v242; // rcx
  SSActorClass *v243; // rcx
  SSActorClass *v244; // rcx
  SSActorClass *v245; // rcx
  SSActorClass *v246; // rcx
  SSActorClass *v247; // rcx
  SSActorClass *v248; // rcx
  SSActorClass *v249; // rcx
  SSActorClass *v250; // rcx
  SSActorClass *v251; // rcx
  SSActorClass *v252; // rcx
  SSActorClass *v253; // rcx
  __m128i v254; // [rsp+30h] [rbp-10h]

  v0 = (SSActorClass *)SSBrain::get_class("Character");
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_despawn;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  UFG::SkookumMgr::mspCharacterClass = v0;
  SSClass::register_method_mthd(
    (SSClass *)&v0->vfptr,
    "despawn",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v1 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_suspend_option;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v1->vfptr,
    "set_suspend_option",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v2 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_invulnerable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v2->vfptr,
    "enable_invulnerable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v3 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_take_damage;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v3->vfptr,
    "enable_take_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v4 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_script_control;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v4->vfptr,
    "enable_script_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v5 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_scripts_during_ai_tree;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v5->vfptr,
    "enable_scripts_during_ai_tree",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v6 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_player_script_control;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v6->vfptr,
    "enable_player_script_control",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_detailed_on_ground;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "enable_detailed_on_ground",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v7 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_lock_player_gameplay_input;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v7->vfptr,
    "lock_player_gameplay_input",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v8 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_player_gameplay_input_locked;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v8->vfptr,
    "is_player_gameplay_input_locked",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v9 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_mission_fail_condition_commit_changes;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v9->vfptr,
    "mission_fail_condition_commit_changes",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v10 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_has_fail_conditions;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v10->vfptr,
    "has_fail_conditions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v11 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_armed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v11->vfptr,
    "is_armed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v12 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_armed_with_non_stowable_weapon;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v12->vfptr,
    "is_armed_with_non_stowable_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v13 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_armed_with;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v13->vfptr,
    "is_armed_with",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_knocked_out;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "is_knocked_out",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v14 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_killed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v14->vfptr,
    "is_killed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v15 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_moving;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v15->vfptr,
    "is_moving",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v16 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_invulnerable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v16->vfptr,
    "is_invulnerable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v17 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_script_controlled;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v17->vfptr,
    "is_script_controlled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v18 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_male;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v18->vfptr,
    "is_male",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v19 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_using_a_vehicle;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v19->vfptr,
    "is_using_a_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v20 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_using_the_vehicle;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v20->vfptr,
    "is_using_the_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v21 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_non_player_damage_multiplier;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v21->vfptr,
    "set_non_player_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v22 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_non_player_damage_multiplier;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v22->vfptr,
    "get_non_player_damage_multiplier",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v23 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v23->vfptr,
    "get_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v24 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v24->vfptr,
    "set_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v25 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_max_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v25->vfptr,
    "get_max_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v26 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_max_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v26->vfptr,
    "set_max_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v27 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_min_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v27->vfptr,
    "get_min_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v28 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_min_health;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v28->vfptr,
    "set_min_health",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v29 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_health_clamped_to_minimum;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v29->vfptr,
    "get_health_clamped_to_minimum",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v30 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_health_clamped_to_minimum;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v30->vfptr,
    "set_health_clamped_to_minimum",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v31 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_regenerative_health_rate;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v31->vfptr,
    "set_regenerative_health_rate",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v32 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_regenerative_health_ratio;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v32->vfptr,
    "set_regenerative_health_ratio",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v33 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_move_stop;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v33->vfptr,
    "move_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v34 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_force_update_targeting;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v34->vfptr,
    "force_update_targeting",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v35 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_is_tired;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v35->vfptr,
    "set_is_tired",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v36 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_attracted_to_pois;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v36->vfptr,
    "set_attracted_to_pois",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v37 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_poi_get_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v37->vfptr,
    "poi_get_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v38 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_poi_use;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v38->vfptr,
    "poi_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v39 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_poi_stop_using_use;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v39->vfptr,
    "poi_stop_using_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v40 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_poi_stop_using;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v40->vfptr,
    "_poi_stop_using",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v41 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_AI_behaviour;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v41->vfptr,
    "set_AI_behaviour",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v42 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_speed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v42->vfptr,
    "set_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v43 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_speed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v43->vfptr,
    "get_speed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v44 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_ignore_ambient_stimuli;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v44->vfptr,
    "set_ignore_ambient_stimuli",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v45 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_jog;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v45->vfptr,
    "allow_jog",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_jog_allowed;
  v46 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v46->vfptr,
    "is_jog_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v47 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_sprint;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v47->vfptr,
    "allow_sprint",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v48 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_sprint_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v48->vfptr,
    "is_sprint_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v49 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_combat_prop_use;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v49->vfptr,
    "allow_combat_prop_use",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v50 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_combat_prop_use_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v50->vfptr,
    "is_combat_prop_use_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v51 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_action_hijack;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v51->vfptr,
    "allow_action_hijack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v52 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_action_hijack_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v52->vfptr,
    "is_action_hijack_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v53 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_vehicle_exit;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v53->vfptr,
    "allow_vehicle_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_vehicle_exit_allowed;
  v254.m128i_i32[2] = 0;
  v54 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v54->vfptr,
    "is_vehicle_exit_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v55 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_vehicle_eject;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v55->vfptr,
    "allow_vehicle_eject",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v56 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_vehicle_eject_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v56->vfptr,
    "is_vehicle_eject_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v57 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_vehicle_shooting;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v57->vfptr,
    "allow_vehicle_shooting",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v58 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_vehicle_shooting_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v58->vfptr,
    "is_vehicle_shooting_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v59 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_sneak_attack;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v59->vfptr,
    "allow_sneak_attack",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v60 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_sneak_attack_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v60->vfptr,
    "is_sneak_attack_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v61 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_hostage_release;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v61->vfptr,
    "allow_hostage_release",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_hostage_release_allowed;
  v254.m128i_i32[2] = 0;
  v62 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v62->vfptr,
    "is_hostage_release_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v63 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_allow_equip_stowed_weapon;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v63->vfptr,
    "allow_equip_stowed_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v64 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_equip_stowed_weapon_allowed;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v64->vfptr,
    "is_equip_stowed_weapon_allowed",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v65 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_action_request_enable_all;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v65->vfptr,
    "action_request_enable_all",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v66 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_action_request_enable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v66->vfptr,
    "action_request_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v67 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_action_request_disable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v67->vfptr,
    "action_request_disable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v68 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_free_aim_intention_xform;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v68->vfptr,
    "set_free_aim_intention_xform",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v69 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_pathing_on_material;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v69->vfptr,
    "enable_pathing_on_material",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_sloppy_freerunning;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "enable_sloppy_freerunning",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v70 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_freerunning;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v70->vfptr,
    "enable_freerunning",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v71 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_xform_to_defend;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v71->vfptr,
    "set_xform_to_defend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v72 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_clear_pos_to_defend;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v72->vfptr,
    "clear_pos_to_defend",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v73 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_spawn_npc_density_adjust;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v73->vfptr,
    "spawn_npc_density_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    1,
    0);
  v74 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_spawn_point_density_adjust;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v74->vfptr,
    "spawn_point_density_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    1,
    0);
  v75 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_spawn_npc_target_count;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v75->vfptr,
    "spawn_npc_target_count",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    1,
    0);
  v76 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_spawn_npc_off_range;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v76->vfptr,
    "spawn_npc_off_range",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    1,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_hidden;
  v77 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v77->vfptr,
    "is_hidden",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v78 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_is_hidden;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v78->vfptr,
    "set_is_hidden",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v79 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_attack_param_real;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v79->vfptr,
    "get_attack_param_real",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v80 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_attack_param_int;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v80->vfptr,
    "get_attack_param_int",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v81 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_max_engagement_distance;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v81->vfptr,
    "set_max_engagement_distance",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v82 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_engage_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v82->vfptr,
    "engage_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v83 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_return_to_default_engagement_of_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v83->vfptr,
    "return_to_default_engagement_of_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v84 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_begin_fleeing;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v84->vfptr,
    "begin_fleeing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_stop_fleeing;
  v254.m128i_i32[2] = 0;
  v85 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v85->vfptr,
    "stop_fleeing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v86 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_add_supplementary_attack_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v86->vfptr,
    "add_supplementary_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v87 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_remove_supplementary_attack_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v87->vfptr,
    "remove_supplementary_attack_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v88 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_add_scary_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v88->vfptr,
    "add_scary_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v89 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_clear_scary_actors;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v89->vfptr,
    "clear_scary_actors",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v90 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_collision_avoidance_type;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v90->vfptr,
    "set_collision_avoidance_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v91 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_reset_collision_avoidance_type;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v91->vfptr,
    "reset_collision_avoidance_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v92 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_objective;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v92->vfptr,
    "get_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_objective;
  v254.m128i_i32[2] = 0;
  v93 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v93->vfptr,
    "set_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v94 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_objective_and_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v94->vfptr,
    "set_objective_and_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v95 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_clear_objective;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v95->vfptr,
    "clear_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v96 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_start_holding_action_request;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v96->vfptr,
    "start_holding_action_request",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v97 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_stop_holding_action_request;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v97->vfptr,
    "stop_holding_action_request",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v98 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_stop_holding_all_action_requests;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v98->vfptr,
    "stop_holding_all_action_requests",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v99 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_melee_weapon;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v99->vfptr,
    "get_melee_weapon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v100 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_firearm;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v100->vfptr,
    "get_firearm",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_firearm_type;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "get_firearm_type",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v101 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_disable_hostile;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v101->vfptr,
    "disable_hostile",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v102 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_hostile;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v102->vfptr,
    "enable_hostile",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v103 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_reset_state;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v103->vfptr,
    "reset_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v104 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_reset_state_keep_items;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v104->vfptr,
    "reset_state_keep_items",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v105 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_reinitialize;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v105->vfptr,
    "reinitialize",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v106 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_grappling_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v106->vfptr,
    "is_grappling_actor",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v107 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_a_driver;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v107->vfptr,
    "is_a_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_the_driver;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "is_the_driver",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v108 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_in_trunk;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v108->vfptr,
    "is_in_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v109 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_in_the_trunk;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v109->vfptr,
    "is_in_the_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v110 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_a_passenger;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v110->vfptr,
    "is_a_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v111 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_the_passenger;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v111->vfptr,
    "is_the_passenger",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v112 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_local_player;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v112->vfptr,
    "is_local_player",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v113 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_trunk_vehicle;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v113->vfptr,
    "get_trunk_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v114 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_current_vehicle;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v114->vfptr,
    "get_current_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_out_of_fight;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v115 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_in_fight;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v115->vfptr,
    "is_in_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v116 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_bone_visual_damage_amount;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v116->vfptr,
    "set_bone_visual_damage_amount",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v117 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_clone_visual_damage;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v117->vfptr,
    "clone_visual_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v118 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_distance_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v118->vfptr,
    "distance_target",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v119 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_distance_target_2d;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v119->vfptr,
    "distance_target_2d",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v120 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_combat_region;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v120->vfptr,
    "set_combat_region",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v121 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_can_gain_attack_rights;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v121->vfptr,
    "set_can_gain_attack_rights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_can_gain_attack_rights;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "get_can_gain_attack_rights",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v122 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_fake_has_hostage;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v122->vfptr,
    "set_fake_has_hostage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v123 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_in_water;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v123->vfptr,
    "is_in_water",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v124 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_paint_effect;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v124->vfptr,
    "set_paint_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v125 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_charred_effect;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v125->vfptr,
    "set_charred_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v126 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_footstep_override_effect;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v126->vfptr,
    "set_footstep_override_effect",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v127 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_invulnerable_to_fire;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v127->vfptr,
    "set_invulnerable_to_fire",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v128 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_health_ui_state;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v128->vfptr,
    "set_health_ui_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v129 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_clear_current_emotion;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v129->vfptr,
    "clear_current_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v130 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_current_emotion;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v130->vfptr,
    "set_current_emotion",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v131 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_standing_adjust;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v131->vfptr,
    "standing_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v132 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_standing_get;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v132->vfptr,
    "standing_get",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v133 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_standing_get_targets;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v133->vfptr,
    "standing_get_targets",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v134 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_standing_set;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v134->vfptr,
    "standing_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v135 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_set_action;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v135->vfptr,
    "face_set_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v136 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_set_purchase_item;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v136->vfptr,
    "face_set_purchase_item",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v137 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_get_action;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v137->vfptr,
    "face_get_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v138 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_get_action_min_requirement;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v138->vfptr,
    "face_get_action_min_requirement",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v139 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_action_auto_completes_objective;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v139->vfptr,
    "face_action_auto_completes_objective",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v140 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_face_meter_set;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v140->vfptr,
    "face_meter_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v141 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v141->vfptr,
    "face_success_state_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v142 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_success;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v142->vfptr,
    "face_is_action_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v143 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_failure;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v143->vfptr,
    "face_is_action_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v144 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_minigame_success;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v144->vfptr,
    "face_is_action_minigame_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v145 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_minigame_failure;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v145->vfptr,
    "face_is_action_minigame_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v146 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_greet_success;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v146->vfptr,
    "face_is_action_greet_success",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v147 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_greet_failure;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v147->vfptr,
    "face_is_action_greet_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v148 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_is_action_other_failure;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v148->vfptr,
    "face_is_action_other_failure",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v149 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_enable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v149->vfptr,
    "face_action_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v150 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_toggle_social_icon;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v150->vfptr,
    "face_toggle_social_icon",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v151 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_minigame_setup;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v151->vfptr,
    "minigame_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v152 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_is_enabled;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v152->vfptr,
    "face_action_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v153 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_is_setup;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v153->vfptr,
    "face_action_is_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_is_minigame_enabled;
  v154 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v154->vfptr,
    "face_action_is_minigame_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v155 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_is_minigame_setup;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v155->vfptr,
    "face_action_is_minigame_setup",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v156 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_action_clear;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v156->vfptr,
    "face_action_clear",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v157 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_get_level;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v157->vfptr,
    "face_get_level",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v158 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_meter_enable;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v158->vfptr,
    "face_meter_enable",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v159 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_meter_is_enabled;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v159->vfptr,
    "face_meter_is_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v160 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_grant_player_buff;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v160->vfptr,
    "grant_player_buff",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v161 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_is_player_buff_active;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v161->vfptr,
    "is_player_buff_active",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_is_playing;
  v254.m128i_i32[2] = 0;
  v162 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v162->vfptr,
    "social_dialogue_is_playing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v163 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_play;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v163->vfptr,
    "social_dialogue_play",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v164 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_stop;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v164->vfptr,
    "social_dialogue_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v165 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_stop_all_conversations;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v165->vfptr,
    "social_dialogue_stop_all_conversations",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v166 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_interaction_set_should_exit;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v166->vfptr,
    "social_interaction_set_should_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v167 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_interaction_should_exit;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v167->vfptr,
    "social_interaction_should_exit",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v168 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_set_should_reset;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v168->vfptr,
    "social_dialogue_set_should_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v169 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_should_reset;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v169->vfptr,
    "social_dialogue_should_reset",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_get_reference;
  v254.m128i_i32[2] = 0;
  v170 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v170->vfptr,
    "social_dialogue_get_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v171 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_set_reference;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v171->vfptr,
    "social_dialogue_set_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v172 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_has_reference;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v172->vfptr,
    "social_dialogue_has_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v173 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_is_valid;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v173->vfptr,
    "social_dialogue_is_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v174 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_get_last_played;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v174->vfptr,
    "social_dialogue_get_last_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v175 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_set_last_played;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v175->vfptr,
    "social_dialogue_set_last_played",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v176 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_interaction_has_occurred;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v176->vfptr,
    "social_interaction_has_occurred",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v177 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_minigame_finished_playing;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v177->vfptr,
    "social_minigame_finished_playing",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_interaction_has_succeeded;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "social_interaction_has_succeeded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v178 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_set_face_action;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v178->vfptr,
    "social_dialogue_set_face_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v179 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_get_face_action;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v179->vfptr,
    "social_dialogue_get_face_action",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v180 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_set_conversation_state;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v180->vfptr,
    "social_dialogue_set_conversation_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v181 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_get_conversation_state;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v181->vfptr,
    "social_dialogue_get_conversation_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v182 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_has_been_greeted;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v182->vfptr,
    "face_has_been_greeted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v183 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_set_greeted;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v183->vfptr,
    "face_set_greeted",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v184 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_set_requires_greet;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v184->vfptr,
    "face_set_requires_greet",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_set_auto_charge;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "face_set_auto_charge",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v185 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_get_success_state;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v185->vfptr,
    "face_get_success_state",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v186 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_face_get_success_state_as_symbol;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v186->vfptr,
    "face_get_success_state_as_symbol",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v187 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_dialogue_get_last_conversation_result;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v187->vfptr,
    "social_dialogue_get_last_conversation_result",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v188 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_play;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v188->vfptr,
    "social_post_interaction_dialogue_play",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v189 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_stop;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v189->vfptr,
    "social_post_interaction_dialogue_stop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v190 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_has_reference;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v190->vfptr,
    "social_post_interaction_dialogue_has_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v191 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_get_reference;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v191->vfptr,
    "social_post_interaction_dialogue_get_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_set_reference;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "social_post_interaction_dialogue_set_reference",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v192 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_post_interaction_dialogue_is_valid;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v192->vfptr,
    "social_post_interaction_dialogue_is_valid",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v193 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::MthdC_social_combat_fast_talk_get_succeeded;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v193->vfptr,
    "social_combat_fast_talk_get_succeeded",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v194 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_money_adjust;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v194->vfptr,
    "money_adjust",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v195 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_money_get;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v195->vfptr,
    "money_get",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v196 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_money_set;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v196->vfptr,
    "money_set",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v197 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_faction;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v197->vfptr,
    "get_faction",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v198 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_faction;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v198->vfptr,
    "set_faction",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_add_follower;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&UFG::SkookumMgr::mspCharacterClass->vfptr,
    "add_follower",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v199 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_equip;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v199->vfptr,
    "equip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v200 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_unequip;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v200->vfptr,
    "unequip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v201 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_stow_equipped_firearm;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v201->vfptr,
    "stow_equipped_firearm",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v202 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_add_to_inventory;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v202->vfptr,
    "add_to_inventory",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v203 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_unlimited_ammo;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v203->vfptr,
    "set_unlimited_ammo",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v204 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_inventory_create_and_equip;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v204->vfptr,
    "inventory_create_and_equip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v205 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_inventory_slot_unequip;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v205->vfptr,
    "inventory_slot_unequip",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v206 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_inventory_slot_set_can_drop;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v206->vfptr,
    "inventory_slot_set_can_drop",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v207 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_inventory_is_equipped;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v207->vfptr,
    "inventory_is_equipped",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v208 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_race;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v208->vfptr,
    "set_race",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v209 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_race_index;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v209->vfptr,
    "get_race_index",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v210 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_force_enter_vehicle;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v210->vfptr,
    "force_enter_vehicle",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v211 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_force_enter_vehicle_seat;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v211->vfptr,
    "force_enter_vehicle_seat",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v212 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_force_enter_vehicle_trunk;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v212->vfptr,
    "force_enter_vehicle_trunk",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v213 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_is_leader;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v213->vfptr,
    "group_is_leader",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v214 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_is_follower;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v214->vfptr,
    "group_is_follower",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v215 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_is_in_my_group;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v215->vfptr,
    "group_is_in_my_group",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v216 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_is_group_member;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v216->vfptr,
    "group_is_group_member",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v217 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_get_leader;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v217->vfptr,
    "group_get_leader",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v218 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_get_members;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v218->vfptr,
    "group_get_members",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v219 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_group_leave;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v219->vfptr,
    "group_leave",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v220 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_can_wander;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v220->vfptr,
    "set_can_wander",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v221 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_enable_in_car_reactions;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v221->vfptr,
    "enable_in_car_reactions",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v222 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_lock_freerun_mode;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v222->vfptr,
    "lock_freerun_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v223 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_unlock_freerun_mode;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v223->vfptr,
    "unlock_freerun_mode",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v224 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_vault_success_rate;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v224->vfptr,
    "set_vault_success_rate",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v225 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_list_gather_characters;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v225->vfptr,
    "list_gather_characters",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v226 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_is_being_grappled;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v226->vfptr,
    "is_being_grappled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v227 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_usable_for_cop_system;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v227->vfptr,
    "set_usable_for_cop_system",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v228 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v228->vfptr,
    "toggle_action_tree_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v229 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v229->vfptr,
    "toggle_ai_action_tree_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v230 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)_;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v230->vfptr,
    "toggle_poi_targeting_debug",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_target_to_choose_targets_near;
  v231 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v231->vfptr,
    "set_target_to_choose_targets_near",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v232 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_interacting_with_vehicle_heuristic;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v232->vfptr,
    "set_interacting_with_vehicle_heuristic",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v233 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_attack_timer;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v233->vfptr,
    "set_attack_timer",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v234 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_sync_to_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v234->vfptr,
    "_sync_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v235 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_submit_action_request;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v235->vfptr,
    "_submit_action_request",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v236 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_move_to_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v236->vfptr,
    "_move_to_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v237 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_path_to_xform;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v237->vfptr,
    "_path_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v238 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_move_to_xform;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v238->vfptr,
    "_move_to_xform",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_move_to_pos;
  v254.m128i_i32[2] = 0;
  v239 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v239->vfptr,
    "_move_to_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v240 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_path_to_pos;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v240->vfptr,
    "_path_to_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v241 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_path_to_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v241->vfptr,
    "_path_to_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v242 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_path_to_target_type;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v242->vfptr,
    "_path_to_target_type",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v243 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_follow_path_safe;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v243->vfptr,
    "_follow_path_safe",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v244 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_rotate_dir;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v244->vfptr,
    "_rotate_dir",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v245 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_rotate_pos;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v245->vfptr,
    "_rotate_pos",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v246 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_rotate_actor;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v246->vfptr,
    "_rotate_actor",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_wait_until_outside_vehicle;
  v254.m128i_i32[2] = 0;
  v247 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v247->vfptr,
    "_wait_until_outside_vehicle",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v248 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSActor::Coro_raycast_to_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v248->vfptr,
    "_raycast_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v249 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_wait_until_objective_is_not;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v249->vfptr,
    "_wait_until_objective_is_not",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v250 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_has_taken_damage;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v250->vfptr,
    "has_taken_damage",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v251 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_get_is_out_of_fight;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v251->vfptr,
    "get_is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v252 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_is_out_of_fight;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v252->vfptr,
    "set_is_out_of_fight",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
  v253 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Mthd_set_animation_lod_enabled;
  _mm_store_si128(&v254, v254);
  SSClass::register_method_mthd(
    (SSClass *)&v253->vfptr,
    "set_animation_lod_enabled",
    (void (__fastcall *)(SSInstance *, SSInvokedMethod *, SSInstance **))&v254,
    0);
}edMethod *, SSInstance **))&v254,
    0);
}nce *, SSInvokedCoroutine *))&v254,
    0);
  v254.m128i_i64[0] = (__int64)UFG::TSCharacter::Coro_wait_until_outside_vehicle;
  v254.m128i_i32[2] = 0;
  v247 = UFG::SkookumMgr::mspCharacterClass;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v247->vfptr,
    "_wait_until_outside_vehicle",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v248 = UFG::SkookumMgr::mspCharacterClass;
  v254.m128i_i32[2] = 0;
  v254.m128i_i64[0] = (__int64)UFG::TSActor::Coro_raycast_to_target;
  _mm_store_si128(&v254, v254);
  SSClass::register_coroutine_mthd(
    (SSClass *)&v248->vfptr,
    "_raycast_to_target",
    (bool (__fastcall *)(SSInstance *, SSInvokedCoroutine *))&v254,
    0);
  v249 = UFG::Skoo

