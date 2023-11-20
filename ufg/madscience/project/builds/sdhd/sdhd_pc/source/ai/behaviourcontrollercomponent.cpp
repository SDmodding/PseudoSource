// File Line: 17
// RVA: 0x14AEAC0
__int64 dynamic_initializer_for__UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList__);
}

// File Line: 18
// RVA: 0x363350
const char *__fastcall UFG::BehaviourControllerComponent::GetTypeName(UFG::BehaviourControllerComponent *this)
{
  return "BehaviourControllerComponent";
}

// File Line: 25
// RVA: 0x37EB40
UFG::BehaviourControllerComponent *__fastcall UFG::BehaviourControllerComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // si
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::BehaviourControllerComponent *v6; // rdi
  UFG::BehaviourControllerComponent *result; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::BehaviourControllerComponent *v11; // rax
  UFG::SimObject *v12; // rdx
  unsigned __int16 v13; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_AIActionTree::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::BehaviourControllerComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( v2 || result )
  {
    v8 = (char *)result->vfptr + (unsigned __int64)result;
    if ( !result->vfptr )
      v8 = 0i64;
    v9 = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(v9, 0x6C0ui64, "BehaviourControllerComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::BehaviourControllerComponent::BehaviourControllerComponent(
        (UFG::BehaviourControllerComponent *)v10,
        v3->m_NameUID,
        v8);
      v6 = v11;
    }
    v12 = v3->m_pSimObject;
    v13 = v12->m_Flags;
    if ( (v13 >> 14) & 1 || (v13 & 0x8000u) != 0 )
      v14 = 19;
    else
      v14 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v15, v12, 1);
    UFG::SimObjectModifier::AttachComponent(&v15, (UFG::SimComponent *)&v6->vfptr, v14);
    UFG::SimObjectModifier::Close(&v15);
    UFG::SimObjectModifier::~SimObjectModifier(&v15);
    result = v6;
  }
  return result;
}

// File Line: 49
// RVA: 0x32CE90
void __fastcall UFG::BehaviourControllerComponent::BehaviourControllerComponent(UFG::BehaviourControllerComponent *this, unsigned int name_uid, const char *actName)
{
  UFG::BehaviourControllerComponent *v3; // rbx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v4; // rdx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v5; // rax
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *v6; // [rsp+58h] [rbp+20h]
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *v7; // [rsp+58h] [rbp+20h]
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *v8; // [rsp+58h] [rbp+20h]

  v3 = this;
  UFG::AIActionTreeComponent::AIActionTreeComponent((UFG::AIActionTreeComponent *)&this->vfptr, name_uid, actName);
  v4 = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::SimComponent};
  v3->vfptr = (UFG::StateInterfaceVtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::StateInterface};
  v3->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::BehaviourControllerComponent::`vftable;
  v3->mExclusiveBehaviour = 0i64;
  v6 = &v3->mParallelBehaviours;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v7 = &v3->mSuspendedStack;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v3->mWaitingBehaviours;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v5 = UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev;
  UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList;
  UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::BehaviourControllerComponent::_BehaviourControllerComponentTypeUID,
    "BehaviourControllerComponent");
}

// File Line: 58
// RVA: 0x335740
void __fastcall UFG::BehaviourControllerComponent::~BehaviourControllerComponent(UFG::BehaviourControllerComponent *this)
{
  UFG::BehaviourControllerComponent *v1; // rsi
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v2; // rdi
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v3; // rcx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v4; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v5; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v6; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v9; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v10; // rax
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v11; // rcx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::StateInterface};
  this->vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::BehaviourControllerComponent::`vftable;
  if ( this == UFG::BehaviourControllerComponent::s_BehaviourControllerComponentpCurrentIterator )
    UFG::BehaviourControllerComponent::s_BehaviourControllerComponentpCurrentIterator = (UFG::BehaviourControllerComponent *)&this->mPrev[-104].mNext;
  v2 = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BehaviourControllerComponent::ClearAllBehaviours(v1);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&v1->mWaitingBehaviours);
  v5 = v1->mWaitingBehaviours.mNode.mPrev;
  v6 = v1->mWaitingBehaviours.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mWaitingBehaviours.mNode.mPrev = &v1->mWaitingBehaviours.mNode;
  v1->mWaitingBehaviours.mNode.mNext = &v1->mWaitingBehaviours.mNode;
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&v1->mSuspendedStack);
  v7 = v1->mSuspendedStack.mNode.mPrev;
  v8 = v1->mSuspendedStack.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mSuspendedStack.mNode.mPrev = &v1->mSuspendedStack.mNode;
  v1->mSuspendedStack.mNode.mNext = &v1->mSuspendedStack.mNode;
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&v1->mParallelBehaviours);
  v9 = v1->mParallelBehaviours.mNode.mPrev;
  v10 = v1->mParallelBehaviours.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v1->mParallelBehaviours.mNode.mPrev = &v1->mParallelBehaviours.mNode;
  v1->mParallelBehaviours.mNode.mNext = &v1->mParallelBehaviours.mNode;
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AIActionTreeComponent::~AIActionTreeComponent((UFG::AIActionTreeComponent *)&v1->vfptr);
}

// File Line: 68
// RVA: 0x34ED80
void __fastcall UFG::BehaviourControllerComponent::ClearAllBehaviours(UFG::BehaviourControllerComponent *this)
{
  UFG::Behaviour *v1; // rdx
  UFG::BehaviourControllerComponent *v2; // rbx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v3; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v4; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v5; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v6; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v9; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v10; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v11; // rax

  v1 = this->mExclusiveBehaviour;
  v2 = this;
  if ( v1 )
    UFG::BehaviourControllerComponent::EndBehaviour(this, v1);
  while ( (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> **)&v2->mParallelBehaviours.mNode.mNext[-2].mNext != &v2->mPrev )
  {
    v3 = v2->mParallelBehaviours.mNode.mNext;
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
    UFG::BehaviourControllerComponent::EndBehaviour(v2, (UFG::Behaviour *)&v3[-2].mNext);
  }
  while ( (UFG::Behaviour **)&v2->mSuspendedStack.mNode.mNext[-2].mNext != &v2->mExclusiveBehaviour )
  {
    v6 = v2->mSuspendedStack.mNode.mNext;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    v6->mNext = v6;
    UFG::BehaviourControllerComponent::EndBehaviour(v2, (UFG::Behaviour *)&v6[-2].mNext);
  }
  while ( &v2->mWaitingBehaviours.mNode.mNext[-2].mNext != &v2->mParallelBehaviours.mNode.mNext )
  {
    v9 = v2->mWaitingBehaviours.mNode.mNext;
    v10 = v9->mPrev;
    v11 = v9->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = v9;
    v9->mNext = v9;
    if ( v9 != (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::Behaviour,UFG::Behaviour> **, signed __int64))v9[-2].mNext->mPrev)(
        &v9[-2].mNext,
        1i64);
  }
}

// File Line: 94
// RVA: 0x380C30
void __fastcall UFG::BehaviourControllerComponent::ReleaseActionTree(UFG::BehaviourControllerComponent *this)
{
  UFG::BehaviourControllerComponent *v1; // rbx

  v1 = this;
  UFG::BehaviourControllerComponent::ClearAllBehaviours(this);
  UFG::AIActionTreeComponent::ReleaseActionTree((UFG::AIActionTreeComponent *)&v1->vfptr);
}

// File Line: 103
// RVA: 0x378A80
void __fastcall UFG::BehaviourControllerComponent::OnAttach(UFG::BehaviourControllerComponent *this, UFG::SimObject *object)
{
  UFG::AIActionTreeComponent::OnAttach((UFG::AIActionTreeComponent *)&this->vfptr, object);
}

// File Line: 111
// RVA: 0x37A4B0
void __fastcall UFG::BehaviourControllerComponent::OnDetach(UFG::BehaviourControllerComponent *this)
{
  UFG::AIActionTreeComponent::OnDetach((UFG::AIActionTreeComponent *)&this->vfptr);
}

// File Line: 119
// RVA: 0x37BDA0
void __fastcall UFG::BehaviourControllerComponent::OnUpdate(UFG::BehaviourControllerComponent *this, float delta_sec)
{
  UFG::BehaviourControllerComponent *v2; // rdi
  UFG::Behaviour *v3; // rdx
  signed __int64 v4; // rdx
  signed __int64 v5; // rbx

  v2 = this;
  if ( !((LOBYTE(this->m_Flags) >> 1) & 1) )
  {
    v3 = this->mExclusiveBehaviour;
    if ( v3 && (!v3->mParams.mInvokeTask || v3->mParams.mControlType) )
      UFG::BehaviourControllerComponent::UpdateBehaviour(this, v3, delta_sec);
    v4 = (signed __int64)&v2->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> **)v4 != &v2->mPrev )
    {
      do
      {
        v5 = *(_QWORD *)(v4 + 32) - 24i64;
        if ( !*(_QWORD *)(v4 + 80) || *(_DWORD *)(v4 + 64) )
          UFG::BehaviourControllerComponent::UpdateBehaviour(v2, (UFG::Behaviour *)v4, delta_sec);
        v4 = v5;
      }
      while ( (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> **)v5 != &v2->mPrev );
    }
    UFG::BehaviourControllerComponent::UpdatePendingBehaviours(v2, delta_sec);
    UFG::AIActionTreeComponent::OnUpdate((UFG::AIActionTreeComponent *)&v2->vfptr, delta_sec);
  }
}

// File Line: 154
// RVA: 0x397D70
void __fastcall UFG::BehaviourControllerComponent::UpdatePendingBehaviours(UFG::BehaviourControllerComponent *this, float timestep)
{
  UFG::BehaviourControllerComponent *v2; // rdi
  float v3; // xmm7_4
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v4; // rsi
  UFG::Behaviour **v5; // rbp
  signed __int64 v6; // rdx
  signed __int64 v7; // rbx
  signed __int64 i; // rcx
  __int64 v9; // rcx
  _QWORD *v10; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v11; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v12; // rax
  UFG::Behaviour *v13; // rdx
  UFG::Behaviour *v14; // rdx
  float v15; // xmm1_4
  float v16; // xmm0_4
  signed __int64 v17; // rbx

  v2 = this;
  v3 = timestep;
  if ( !this->mExclusiveBehaviour )
  {
    v4 = &this->mParallelBehaviours.mNode.mNext;
    v5 = &this->mExclusiveBehaviour;
    do
    {
      if ( (UFG::Behaviour **)&v2->mSuspendedStack.mNode.mNext[-2].mNext == v5 )
        v6 = 0i64;
      else
        v6 = (signed __int64)&v2->mSuspendedStack.mNode.mNext[-2].mNext;
      v7 = 0i64;
      for ( i = (signed __int64)&v2->mWaitingBehaviours.mNode.mNext[-2].mNext;
            (UFG::qNode<UFG::Behaviour,UFG::Behaviour> **)i != v4;
            i = *(_QWORD *)(i + 32) - 24i64 )
      {
        if ( !v7 || *(_DWORD *)(v7 + 56) < *(_DWORD *)(i + 56) )
          v7 = i;
      }
      if ( v6 )
      {
        if ( v7 )
        {
          if ( *(_DWORD *)(v6 + 56) >= *(_DWORD *)(v7 + 56) )
            v7 = v6;
        }
        else
        {
          v7 = v6;
        }
      }
      else if ( !v7 )
      {
        break;
      }
      if ( v7 )
      {
        v9 = *(_QWORD *)(v7 + 24);
        v10 = *(_QWORD **)(v7 + 32);
        v11 = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)(v7 + 24);
        *(_QWORD *)(v9 + 8) = v10;
        *v10 = v9;
        v11->mPrev = v11;
        v11->mNext = v11;
        if ( *(_DWORD *)(v7 + 44) == 2 )
        {
          if ( *(_DWORD *)(v7 + 60) == 4 )
          {
            v12 = v2->mParallelBehaviours.mNode.mPrev;
            v12->mNext = v11;
            v11->mPrev = v12;
            *(_QWORD *)(v7 + 32) = (char *)v2 + 1680;
            v2->mParallelBehaviours.mNode.mPrev = v11;
            v2->mExclusiveBehaviour->mState = 1;
            v2->mExclusiveBehaviour = (UFG::Behaviour *)v7;
          }
          else
          {
            v13 = v2->mExclusiveBehaviour;
            if ( v13 )
              UFG::BehaviourControllerComponent::EndBehaviour(v2, v13);
            v2->mExclusiveBehaviour = (UFG::Behaviour *)v7;
            *(_DWORD *)(v7 + 44) = 1;
            v2->mExclusiveBehaviour = (UFG::Behaviour *)v7;
          }
        }
        else if ( (unsigned int)UFG::BehaviourControllerComponent::BeginBehaviour(v2, (UFG::Behaviour *)v7, 0i64) == 1 )
        {
          v2->mExclusiveBehaviour = (UFG::Behaviour *)v7;
        }
        else
        {
          UFG::BehaviourControllerComponent::EndBehaviour(v2, (UFG::Behaviour *)v7);
        }
      }
    }
    while ( !v2->mExclusiveBehaviour );
  }
  v14 = (UFG::Behaviour *)&v2->mWaitingBehaviours.mNode.mNext[-2].mNext;
  if ( v14 != (UFG::Behaviour *)&v2->mParallelBehaviours.mNode.mNext )
  {
    do
    {
      v15 = v14->mParams.mMaxWaitTime;
      v16 = v3 + v14->mAge;
      v17 = (signed __int64)&v14->mNext[-2].mNext;
      v14->mAge = v16;
      if ( v15 > 0.0 && v16 > v15 )
        UFG::BehaviourControllerComponent::EndBehaviour(v2, v14);
      v14 = (UFG::Behaviour *)v17;
    }
    while ( (UFG::qNode<UFG::Behaviour,UFG::Behaviour> **)v17 != &v2->mParallelBehaviours.mNode.mNext );
  }
}

// File Line: 250
// RVA: 0x369760
__int64 __fastcall UFG::BehaviourControllerComponent::InvokeBehaviour(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, UFG::InvokeBehaviourResult *optResult)
{
  JUMPOUT(params->mPriorityMode, 4, UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel);
  JUMPOUT(params->mIsRootInvoke, 0, UFG::BehaviourControllerComponent::Arbitrate_StartChild);
  return UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(this, params, optResult);
}

// File Line: 274
// RVA: 0x341B70
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartChild(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, UFG::InvokeBehaviourResult *optResult)
{
  unsigned int v3; // esi
  UFG::InvokeBehaviourResult *v4; // rbx
  UFG::InvokeBehaviourParams *v5; // rdi
  UFG::BehaviourControllerComponent *v6; // rbp
  UFG::Behaviour *v7; // r14
  UFG::eInvokeBehaviourControl v8; // eax
  signed int v9; // eax
  UFG::Behaviour *v10; // rax
  InvokeBehaviourTask *v11; // rax
  UFG::Behaviour *v12; // rax
  UFG::Behaviour *v13; // rdi
  UFG::InvokeBehaviourParams paramsa; // [rsp+20h] [rbp-38h]

  v3 = 0;
  v4 = optResult;
  v5 = params;
  v6 = this;
  if ( optResult )
  {
    optResult->mId = 0;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customWorldMapCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  v7 = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(this, params->mInvokeTask);
  v8 = v5->mControlType;
  if ( v8 )
  {
    if ( v8 != 1 )
      return v3;
    v9 = v5->mPriorityMode;
    if ( v9 < 0 )
      return v3;
    if ( v9 > 1 )
    {
      if ( v9 > 3 )
        return v3;
      v10 = v6->mExclusiveBehaviour;
      if ( v7 == v10 )
      {
        v3 = -1;
        if ( v4 )
        {
          v4->mId = -1;
          v4->mBehaviour = v10;
          v4->mDesc = "Child track of exclusive behaviour cannot suspend the parent.";
          v4->mInvokeParams.mNode = v5->mNode;
          *(_QWORD *)&v4->mInvokeParams.mPriority = *(_QWORD *)&v5->mPriority;
          *(_QWORD *)&v4->mInvokeParams.mControlType = *(_QWORD *)&v5->mControlType;
          *(_QWORD *)&v4->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v5->mMaxLifeTime;
          v4->mInvokeParams.mInvokeTask = v5->mInvokeTask;
        }
        return v3;
      }
    }
    paramsa.mNode = v5->mNode;
    *(_QWORD *)&paramsa.mPriority = *(_QWORD *)&v5->mPriority;
    *(_QWORD *)&paramsa.mControlType = *(_QWORD *)&v5->mControlType;
    *(_QWORD *)&paramsa.mMaxLifeTime = *(_QWORD *)&v5->mMaxLifeTime;
    v11 = v5->mInvokeTask;
    paramsa.mIsRootInvoke = 1;
    paramsa.mInvokeTask = v11;
    v3 = UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(v6, &paramsa, v4);
    if ( v3 != 1 )
      return v3;
  }
  v12 = UFG::BehaviourControllerComponent::CreateBehaviour(v6, v5, v7 == 0i64, v4);
  v13 = v12;
  if ( v12 )
  {
    if ( v7 )
      v12->mParams.mPriority = v7->mParams.mPriority;
    else
      v6->mExclusiveBehaviour = v12;
    v3 = UFG::BehaviourControllerComponent::BeginBehaviour(v6, v12, v4);
    if ( v3 != 1 )
      UFG::BehaviourControllerComponent::EndBehaviour(v6, v13);
  }
  else if ( v4 )
  {
    v3 = v4->mId;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

// File Line: 379
// RVA: 0x341F50
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, UFG::InvokeBehaviourResult *optResult)
{
  UFG::InvokeBehaviourResult *v3; // rbx
  UFG::InvokeBehaviourParams *v4; // rdi
  UFG::BehaviourControllerComponent *v5; // rsi
  UFG::Behaviour *v6; // rcx
  unsigned int v7; // ebp
  UFG::Behaviour *v8; // rdx
  UFG::Behaviour *v9; // rdx
  const char *v10; // rax
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *v11; // r14
  UFG::Behaviour *v12; // rcx
  UFG::Behaviour *v13; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v14; // rcx
  UFG::Behaviour *v15; // rdi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v16; // rax

  v3 = optResult;
  v4 = params;
  v5 = this;
  if ( optResult )
  {
    optResult->mId = 0;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customWorldMapCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  v6 = this->mExclusiveBehaviour;
  if ( v6 && v6->mParams.mNode == params->mNode )
  {
    v7 = -5;
    if ( optResult )
    {
      optResult->mId = -5;
      optResult->mBehaviour = v6;
      optResult->mDesc = "Parallel behaviour requested is already running as EXCLUSIVE.";
      optResult->mInvokeParams = *params;
    }
    return v7;
  }
  v8 = (UFG::Behaviour *)&v5->mSuspendedStack.mNode.mNext[-2].mNext;
  if ( v8 == (UFG::Behaviour *)&v5->mExclusiveBehaviour )
  {
LABEL_11:
    v9 = (UFG::Behaviour *)&v5->mWaitingBehaviours.mNode.mNext[-2].mNext;
    if ( v9 != (UFG::Behaviour *)&v5->mParallelBehaviours.mNode.mNext )
    {
      while ( v9->mParams.mNode != v4->mNode )
      {
        v9 = (UFG::Behaviour *)&v9->mNext[-2].mNext;
        if ( v9 == (UFG::Behaviour *)&v5->mParallelBehaviours.mNode.mNext )
          goto LABEL_20;
      }
      UFG::BehaviourControllerComponent::EndBehaviour(v5, v9);
      if ( v3 )
      {
        v10 = "Removed existing behaviour from waiting list.";
        goto LABEL_19;
      }
    }
  }
  else
  {
    while ( v8->mParams.mNode != v4->mNode )
    {
      v8 = (UFG::Behaviour *)&v8->mNext[-2].mNext;
      if ( v8 == (UFG::Behaviour *)&v5->mExclusiveBehaviour )
        goto LABEL_11;
    }
    UFG::BehaviourControllerComponent::EndBehaviour(v5, v8);
    if ( v3 )
    {
      v10 = "Removed existing behaviour from suspended stack.";
LABEL_19:
      v3->mId = 0;
      v3->mDesc = v10;
      v3->mBehaviour = 0i64;
      v3->mInvokeParams.mNode = v4->mNode;
      *(_QWORD *)&v3->mInvokeParams.mPriority = *(_QWORD *)&v4->mPriority;
      *(_QWORD *)&v3->mInvokeParams.mControlType = *(_QWORD *)&v4->mControlType;
      *(_QWORD *)&v3->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v4->mMaxLifeTime;
      v3->mInvokeParams.mInvokeTask = v4->mInvokeTask;
      goto LABEL_20;
    }
  }
LABEL_20:
  v11 = &v5->mParallelBehaviours;
  v12 = (UFG::Behaviour *)&v5->mParallelBehaviours.mNode.mNext[-2].mNext;
  if ( v12 == (UFG::Behaviour *)&v5->mPrev )
    goto LABEL_23;
  while ( v12->mParams.mNode != v4->mNode )
  {
    v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&v5->mPrev )
      goto LABEL_23;
  }
  if ( v4->mPriority > v12->mParams.mPriority )
  {
    UFG::BehaviourControllerComponent::EndBehaviour(v5, v12);
LABEL_23:
    v13 = UFG::BehaviourControllerComponent::CreateBehaviour(v5, v4, 0, 0i64);
    v14 = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&v13->mPrev;
    v15 = v13;
    v16 = v11->mNode.mPrev;
    v16->mNext = v14;
    v14->mPrev = v16;
    v14->mNext = &v11->mNode;
    v11->mNode.mPrev = v14;
    v7 = UFG::BehaviourControllerComponent::BeginBehaviour(v5, v15, v3);
    if ( v7 != 1 )
      UFG::BehaviourControllerComponent::EndBehaviour(v5, v15);
    return v7;
  }
  v7 = -5;
  if ( v3 )
  {
    v3->mId = -5;
    v3->mBehaviour = v12;
    v3->mDesc = "Instance of parallel behaviour already running with higher priority.";
    v3->mInvokeParams.mNode = v4->mNode;
    *(_QWORD *)&v3->mInvokeParams.mPriority = *(_QWORD *)&v4->mPriority;
    *(_QWORD *)&v3->mInvokeParams.mControlType = *(_QWORD *)&v4->mControlType;
    *(_QWORD *)&v3->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v4->mMaxLifeTime;
    v3->mInvokeParams.mInvokeTask = v4->mInvokeTask;
  }
  return v7;
}

// File Line: 446
// RVA: 0x341D30
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, UFG::InvokeBehaviourResult *optResult)
{
  UFG::InvokeBehaviourResult *v3; // rbx
  UFG::InvokeBehaviourParams *v4; // rsi
  UFG::BehaviourControllerComponent *v5; // rbp
  unsigned int v6; // edi
  UFG::Behaviour *v7; // rcx
  UFG::eInvokeBehaviourPriorityMode v8; // edx
  UFG::Behaviour *v9; // rax
  UFG::Behaviour *v10; // rax
  UFG::Behaviour *v11; // rsi

  v3 = optResult;
  v4 = params;
  v5 = this;
  v6 = this->mExclusiveBehaviour == 0i64;
  if ( optResult )
  {
    optResult->mId = v6;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customWorldMapCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  v7 = this->mExclusiveBehaviour;
  if ( !v7 || (v8 = params->mPriorityMode, (signed int)v8 < 0) )
  {
LABEL_24:
    if ( v6 != 1 )
      return v6;
    goto LABEL_25;
  }
  if ( (signed int)v8 <= 1 )
  {
    if ( v4->mPriority > v7->mParams.mPriority )
    {
      UFG::BehaviourControllerComponent::EndBehaviour(v5, v7);
LABEL_25:
      v10 = UFG::BehaviourControllerComponent::CreateBehaviour(v5, v4, 1, v3);
      v11 = v10;
      if ( v10 )
      {
        v5->mExclusiveBehaviour = v10;
        v6 = UFG::BehaviourControllerComponent::BeginBehaviour(v5, v10, v3);
        if ( v6 != 1 )
          UFG::BehaviourControllerComponent::EndBehaviour(v5, v11);
      }
      else if ( v3 )
      {
        v6 = v3->mId;
      }
      else
      {
        v6 = 0;
      }
      return v6;
    }
    if ( v8 == 1 )
    {
      v9 = UFG::BehaviourControllerComponent::CreateWaitingBehaviour(v5, v4, optResult);
      if ( v9 )
      {
LABEL_12:
        v6 = 2;
        if ( v3 )
        {
          v3->mId = 2;
          v3->mBehaviour = v9;
          v3->mDesc = "Waiting";
          v3->mInvokeParams.mNode = v4->mNode;
          *(_QWORD *)&v3->mInvokeParams.mPriority = *(_QWORD *)&v4->mPriority;
          *(_QWORD *)&v3->mInvokeParams.mControlType = *(_QWORD *)&v4->mControlType;
          *(_QWORD *)&v3->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v4->mMaxLifeTime;
          v3->mInvokeParams.mInvokeTask = v4->mInvokeTask;
        }
        return v6;
      }
      if ( !v3 )
        return (unsigned int)-2;
      goto LABEL_23;
    }
  }
  else
  {
    if ( (signed int)v8 > 3 )
      goto LABEL_24;
    if ( v4->mPriority > v7->mParams.mPriority )
    {
      UFG::BehaviourControllerComponent::SuspendBehaviour(v5, v7);
      goto LABEL_25;
    }
    if ( v8 == 3 )
    {
      v9 = UFG::BehaviourControllerComponent::CreateWaitingBehaviour(v5, v4, optResult);
      if ( v9 )
        goto LABEL_12;
      if ( !v3 )
        return (unsigned int)-2;
LABEL_23:
      v6 = v3->mId;
      goto LABEL_24;
    }
  }
  v6 = -4;
  if ( optResult )
  {
    optResult->mId = -4;
    optResult->mBehaviour = v7;
    optResult->mDesc = "Priority is lower than currently running behaviour.";
    optResult->mInvokeParams.mNode = v4->mNode;
    *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&v4->mPriority;
    *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&v4->mControlType;
    *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v4->mMaxLifeTime;
    optResult->mInvokeParams.mInvokeTask = v4->mInvokeTask;
  }
  return v6;
}

// File Line: 555
// RVA: 0x3509C0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::CreateBehaviour(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, bool bCheckForDuplicates, UFG::InvokeBehaviourResult *optResult)
{
  UFG::InvokeBehaviourResult *v4; // rbx
  UFG::InvokeBehaviourParams *v5; // rdi
  UFG::BehaviourControllerComponent *v6; // r9
  bool v7; // si
  UFG::Behaviour *v8; // rcx
  UFG::Behaviour *v9; // rcx
  ActionNode *v10; // rdx
  const char *v11; // rax
  UFG::Behaviour *v12; // rdx
  UFG::Behaviour *v13; // rdx
  UFG::allocator::free_link *v14; // rax
  UFG::Behaviour *v15; // rax
  UFG::Behaviour *v16; // rbx
  InvokeBehaviourTask *v17; // rax
  UFG::Behaviour *result; // rax
  UFG::allocator::free_link *v19; // rax
  ActionContext *v20; // rax
  char *v21; // rax
  ActionController *v22; // rax

  v4 = optResult;
  v5 = params;
  v6 = this;
  v7 = bCheckForDuplicates == 0;
  if ( bCheckForDuplicates )
  {
    v8 = this->mExclusiveBehaviour;
    if ( v8 && v8->mParams.mNode == params->mNode && v4 )
    {
      v4->mId = -5;
      v4->mDesc = "Invoked behaviour already running as exclusive, this shouldnt happen, bad logic!!";
      v4->mBehaviour = v8;
      v4->mInvokeParams = *params;
    }
    v9 = (UFG::Behaviour *)&v6->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( v9 != (UFG::Behaviour *)&v6->mPrev )
    {
      v10 = params->mNode;
      while ( v9->mParams.mNode != v10 )
      {
        v9 = (UFG::Behaviour *)&v9->mNext[-2].mNext;
        if ( v9 == (UFG::Behaviour *)&v6->mPrev )
          goto LABEL_16;
      }
      if ( v5->mPriority <= v9->mParams.mPriority )
      {
        if ( !v4 )
          goto LABEL_31;
        v4->mId = -5;
        v11 = "Duplicate parallel behaviour with higher priority.";
        v4->mBehaviour = v9;
        goto LABEL_29;
      }
      v7 = 1;
      UFG::BehaviourControllerComponent::EndBehaviour(v6, v9);
      if ( !v4 )
        goto LABEL_31;
      v11 = "Behaviour removed from the Parallel list.";
LABEL_28:
      v4->mId = 1;
      v4->mBehaviour = 0i64;
LABEL_29:
      v4->mDesc = v11;
      v4->mInvokeParams.mNode = v5->mNode;
      *(_QWORD *)&v4->mInvokeParams.mPriority = *(_QWORD *)&v5->mPriority;
      *(_QWORD *)&v4->mInvokeParams.mControlType = *(_QWORD *)&v5->mControlType;
      *(_QWORD *)&v4->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v5->mMaxLifeTime;
      v4->mInvokeParams.mInvokeTask = v5->mInvokeTask;
      goto LABEL_31;
    }
LABEL_16:
    v12 = (UFG::Behaviour *)&v6->mSuspendedStack.mNode.mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&v6->mExclusiveBehaviour )
    {
LABEL_22:
      v13 = (UFG::Behaviour *)&v6->mWaitingBehaviours.mNode.mNext[-2].mNext;
      if ( v13 == (UFG::Behaviour *)&v6->mParallelBehaviours.mNode.mNext )
      {
LABEL_30:
        v7 = 1;
      }
      else
      {
        while ( v13->mParams.mNode != v5->mNode )
        {
          v13 = (UFG::Behaviour *)&v13->mNext[-2].mNext;
          if ( v13 == (UFG::Behaviour *)&v6->mParallelBehaviours.mNode.mNext )
            goto LABEL_30;
        }
        v7 = 1;
        UFG::BehaviourControllerComponent::EndBehaviour(v6, v13);
        if ( v4 )
        {
          v11 = "Behaviour removed from the Waiting list.";
          goto LABEL_28;
        }
      }
    }
    else
    {
      while ( v12->mParams.mNode != v5->mNode )
      {
        v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
        if ( v12 == (UFG::Behaviour *)&v6->mExclusiveBehaviour )
          goto LABEL_22;
      }
      v7 = 1;
      UFG::BehaviourControllerComponent::EndBehaviour(v6, v12);
      if ( v4 )
      {
        v11 = "Behaviour removed from the Suspended stack.";
        goto LABEL_28;
      }
    }
  }
LABEL_31:
  if ( !v7 )
    return 0i64;
  v14 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
  if ( v14 )
  {
    UFG::Behaviour::Behaviour((UFG::Behaviour *)v14, v5);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = v5->mInvokeTask;
  if ( !v17 || v5->mControlType )
  {
    v19 = UFG::qMalloc(0xD8ui64, "Behaviour.ActionContext", 0i64);
    if ( v19 )
      ActionContext::ActionContext((ActionContext *)v19);
    else
      v20 = 0i64;
    v16->mActionContext = v20;
    v21 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x118ui64, "Behaviour.ActionController", 0i64, 1u);
    if ( v21 )
      ActionController::ActionController((ActionController *)v21);
    else
      v22 = 0i64;
    v16->mActionController = v22;
    v16->mParams.mInvokeTask = 0i64;
    result = v16;
  }
  else
  {
    v16->mActionContext = &v17->m_ActionContext;
    v16->mActionController = &v5->mInvokeTask->m_ActionController;
    result = v16;
  }
  return result;
}

// File Line: 623
// RVA: 0x357B50
UFG::qNode<UFG::Behaviour,UFG::Behaviour> **__fastcall UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(UFG::BehaviourControllerComponent *this, InvokeBehaviourTask *task, UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *behList)
{
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v3; // rsi
  InvokeBehaviourTask *v4; // rdi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v5; // rbx
  UFG::BehaviourControllerComponent *v6; // rbp

  v3 = &behList[-2].mNode.mNext;
  v4 = task;
  v5 = &behList->mNode.mNext[-2].mNext;
  v6 = this;
  if ( v5 == &behList[-2].mNode.mNext )
    return 0i64;
  while ( !v4
       || !v5
       || !UFG::BehaviourControllerComponent::IsTaskChildOfController(
             v6,
             (ITask *)&v4->vfptr,
             (ActionController *)v5[12]) )
  {
    v5 = &v5[4][-2].mNext;
    if ( v5 == v3 )
      return 0i64;
  }
  return v5;
}

// File Line: 636
// RVA: 0x357AC0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(UFG::BehaviourControllerComponent *this, InvokeBehaviourTask *task)
{
  UFG::Behaviour *v2; // r8
  InvokeBehaviourTask *v3; // rdi
  UFG::BehaviourControllerComponent *v4; // rbx
  UFG::Behaviour *result; // rax

  v2 = this->mExclusiveBehaviour;
  v3 = task;
  v4 = this;
  if ( !v2
    || !task
    || !UFG::BehaviourControllerComponent::IsTaskChildOfController(this, (ITask *)&task->vfptr, v2->mActionController)
    || (result = v4->mExclusiveBehaviour) == 0i64 )
  {
    result = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(v4, v3, &v4->mParallelBehaviours);
    if ( !result )
    {
      result = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(v4, v3, &v4->mSuspendedStack);
      if ( !result )
        result = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(v4, v3, &v4->mWaitingBehaviours);
    }
  }
  return result;
}

// File Line: 665
// RVA: 0x355F00
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindBehaviourWithNode(UFG::BehaviourControllerComponent *this, const char *nodePath)
{
  UFG::BehaviourControllerComponent *v2; // rdi
  UFG::Behaviour *v3; // rbx
  ActionNode *v4; // rax
  int v5; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  v2 = this;
  v3 = 0i64;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, nodePath);
  v4 = ActionNode::Find(&absolutePath, 0i64);
  if ( v4 )
    v3 = UFG::BehaviourControllerComponent::FindBehaviourWithNode(v2, v4);
  v5 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      v5 = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v5 & 0x80000000;
  }
  return v3;
}

// File Line: 677
// RVA: 0x355FA0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindBehaviourWithNode(UFG::BehaviourControllerComponent *this, ActionNode *node)
{
  UFG::Behaviour *result; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v3; // rax
  UFG::Behaviour *v4; // rcx

  result = this->mExclusiveBehaviour;
  if ( !result || result->mParams.mNode != node )
  {
    result = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( result == (UFG::Behaviour *)&this->mPrev )
    {
LABEL_6:
      result = (UFG::Behaviour *)&this->mSuspendedStack.mNode.mNext[-2].mNext;
      if ( result == (UFG::Behaviour *)&this->mExclusiveBehaviour )
      {
LABEL_9:
        v3 = this->mWaitingBehaviours.mNode.mNext;
        v4 = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext;
        result = (UFG::Behaviour *)&v3[-2].mNext;
        if ( result == v4 )
        {
LABEL_12:
          result = 0i64;
        }
        else
        {
          while ( result->mParams.mNode != node )
          {
            result = (UFG::Behaviour *)&result->mNext[-2].mNext;
            if ( result == v4 )
              goto LABEL_12;
          }
        }
      }
      else
      {
        while ( result->mParams.mNode != node )
        {
          result = (UFG::Behaviour *)&result->mNext[-2].mNext;
          if ( result == (UFG::Behaviour *)&this->mExclusiveBehaviour )
            goto LABEL_9;
        }
      }
    }
    else
    {
      while ( result->mParams.mNode != node )
      {
        result = (UFG::Behaviour *)&result->mNext[-2].mNext;
        if ( result == (UFG::Behaviour *)&this->mPrev )
          goto LABEL_6;
      }
    }
  }
  return result;
}

// File Line: 709
// RVA: 0x351620
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::CreateWaitingBehaviour(UFG::BehaviourControllerComponent *this, UFG::InvokeBehaviourParams *params, UFG::InvokeBehaviourResult *optResult)
{
  UFG::BehaviourControllerComponent *v3; // rdi
  UFG::Behaviour *v4; // rcx
  UFG::Behaviour *v5; // r9
  UFG::InvokeBehaviourParams *v6; // rbx
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *v8; // rsi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v9; // rcx
  ActionNode *v10; // rdx
  UFG::Behaviour *v11; // rax
  UFG::Behaviour *v12; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v13; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v14; // rdx

  v3 = this;
  v4 = this->mExclusiveBehaviour;
  v5 = 0i64;
  v6 = params;
  if ( v4 && v4->mParams.mNode == params->mNode )
  {
    if ( optResult )
    {
      optResult->mId = -5;
      optResult->mBehaviour = v4;
      optResult->mDesc = "Invoked behaviour already running as exclusive.";
      optResult->mInvokeParams = *params;
      return 0i64;
    }
    return v5;
  }
  v8 = &v3->mWaitingBehaviours;
  v9 = &v3->mWaitingBehaviours.mNode.mNext[-2].mNext;
  if ( v9 != &v3->mParallelBehaviours.mNode.mNext )
  {
    v10 = params->mNode;
    while ( v9[6] != (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)v10 )
    {
      v9 = &v9[4][-2].mNext;
      if ( v9 == &v3->mParallelBehaviours.mNode.mNext )
        goto LABEL_9;
    }
    v5 = (UFG::Behaviour *)v9;
    if ( v6->mPriority > *((_DWORD *)v9 + 14) )
    {
      v9[6] = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)v10;
      v9[7] = *(UFG::qNode<UFG::Behaviour,UFG::Behaviour> **)&v6->mPriority;
      v9[8] = *(UFG::qNode<UFG::Behaviour,UFG::Behaviour> **)&v6->mControlType;
      v9[9] = *(UFG::qNode<UFG::Behaviour,UFG::Behaviour> **)&v6->mMaxLifeTime;
      v9[10] = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)v6->mInvokeTask;
      return (UFG::Behaviour *)v9;
    }
    return v5;
  }
LABEL_9:
  v11 = (UFG::Behaviour *)&v3->mParallelBehaviours.mNode.mNext[-2].mNext;
  if ( v11 != (UFG::Behaviour *)&v3->mPrev )
  {
    while ( v11->mParams.mNode != v6->mNode )
    {
      v11 = (UFG::Behaviour *)&v11->mNext[-2].mNext;
      if ( v11 == (UFG::Behaviour *)&v3->mPrev )
        goto LABEL_12;
    }
    if ( !optResult )
      return v5;
    optResult->mBehaviour = v11;
    optResult->mDesc = "Behaviour already running as parallel.";
    goto LABEL_25;
  }
LABEL_12:
  v12 = (UFG::Behaviour *)&v3->mSuspendedStack.mNode.mNext[-2].mNext;
  if ( v12 == (UFG::Behaviour *)&v3->mExclusiveBehaviour )
  {
LABEL_15:
    v5 = UFG::BehaviourControllerComponent::CreateBehaviour(v3, v6, 0, 0i64);
    v5->mState = 3;
    v13 = v8->mNode.mPrev;
    v14 = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&v5->mPrev;
    v13->mNext = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&v5->mPrev;
    v14->mPrev = v13;
    v14->mNext = &v8->mNode;
    v8->mNode.mPrev = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&v5->mPrev;
    return v5;
  }
  while ( v12->mParams.mNode != v6->mNode )
  {
    v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&v3->mExclusiveBehaviour )
      goto LABEL_15;
  }
  if ( v6->mPriority > v12->mParams.mPriority )
  {
    UFG::BehaviourControllerComponent::EndBehaviour(v3, v12);
    goto LABEL_15;
  }
  if ( !optResult )
    return v5;
  optResult->mBehaviour = v12;
  optResult->mDesc = "Behaviour with higher priority is in the Suspended stack.";
LABEL_25:
  optResult->mId = -5;
  optResult->mInvokeParams.mNode = v6->mNode;
  *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&v6->mPriority;
  *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&v6->mControlType;
  *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&v6->mMaxLifeTime;
  optResult->mInvokeParams.mInvokeTask = v6->mInvokeTask;
  return 0i64;
}

// File Line: 764
// RVA: 0x355780
signed __int64 __fastcall UFG::BehaviourControllerComponent::EndBehaviour(UFG::BehaviourControllerComponent *this, const char *nodePath)
{
  UFG::BehaviourControllerComponent *v2; // rbx
  ActionNode *v3; // rax
  unsigned int v4; // ebx
  UFG::Behaviour *v5; // rax
  int v6; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  v2 = this;
  if ( !nodePath || !*nodePath )
    return UFG::BehaviourControllerComponent::EndBehaviour(this, this->mExclusiveBehaviour);
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, nodePath);
  v3 = ActionNode::Find(&absolutePath, 0i64);
  if ( v3 )
  {
    v5 = UFG::BehaviourControllerComponent::FindBehaviourWithNode(v2, v3);
    v4 = UFG::BehaviourControllerComponent::EndBehaviour(v2, v5);
  }
  else
  {
    v4 = -3;
  }
  v6 = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        v6 = absolutePath.mPath.mCount;
      }
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = v6 & 0x80000000;
  }
  return v4;
}

// File Line: 784
// RVA: 0x355690
signed __int64 __fastcall UFG::BehaviourControllerComponent::EndBehaviour(UFG::BehaviourControllerComponent *this, UFG::Behaviour *behaviour)
{
  UFG::Behaviour *v2; // rbx
  UFG::BehaviourControllerComponent *v3; // rdi
  UFG::SimObject *v4; // rcx
  UEL::ParametersBase *v5; // rsi
  unsigned __int16 v6; // dx
  UEL::ParametersBase *v7; // rax

  v2 = behaviour;
  v3 = this;
  if ( behaviour )
  {
    if ( behaviour->mActionController )
    {
      v4 = this->m_pSimObject;
      v5 = UEL::gCurrentParameters;
      if ( v4 )
      {
        v6 = v4->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v7 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
          else
            v7 = (UEL::ParametersBase *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)v4,
                                                            UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                             v4,
                                                                                             UFG::UELComponent::_TypeUID));
        }
        else
        {
          v7 = (UEL::ParametersBase *)v4->m_Components.p->m_pComponent;
        }
        if ( v7 )
          UEL::gCurrentParameters = v7 + 88;
      }
      ActionController::Stop(v2->mActionController);
      UEL::gCurrentParameters = v5;
    }
    if ( v2 == v3->mExclusiveBehaviour )
      v3->mExclusiveBehaviour = 0i64;
    v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Behaviour> *)&v2->vfptr, 1u);
  }
  return 1i64;
}

// File Line: 828
// RVA: 0x36BC80
bool __fastcall UFG::BehaviourControllerComponent::IsTaskChildOfController(UFG::BehaviourControllerComponent *this, ITask *task, ActionController *controller)
{
  ITask *v3; // rbp
  UFG::qNode<ITask,ITask> **v4; // rbx
  bool v5; // di
  UFG::qNode<ITask,ITask> *v6; // rsi
  UFG::BehaviourControllerComponent *v8; // [rsp+40h] [rbp+8h]
  ActionController *v9; // [rsp+50h] [rbp+18h]

  v9 = controller;
  v8 = this;
  v3 = task;
  if ( !task )
    return 0;
  v4 = &controller->m_RunningTasks.mNode.mNext[-1].mNext;
  if ( v4 == (UFG::qNode<ITask,ITask> **)&controller->m_SequenceNode )
    return 0;
  do
  {
    v5 = v4 == (UFG::qNode<ITask,ITask> **)v3;
    if ( v4 == (UFG::qNode<ITask,ITask> **)v3 )
      break;
    v6 = v4[3];
    if ( SpawnTrack::sClassNameUID == ((unsigned int (__fastcall *)(UFG::qNode<ITask,ITask> *))v6->mPrev[2].mNext)(v6)
      || InvokeBehaviourTrack::sClassNameUID == ((unsigned int (__fastcall *)(UFG::qNode<ITask,ITask> *))v6->mPrev[2].mNext)(v6) )
    {
      v5 = UFG::BehaviourControllerComponent::IsTaskChildOfController(v8, v3, (ActionController *)(v4 + 36));
      if ( v5 )
        break;
    }
    v4 = &v4[2][-1].mNext;
  }
  while ( v4 != (UFG::qNode<ITask,ITask> **)&v9->m_SequenceNode );
  return v5;
}

// File Line: 864
// RVA: 0x3491E0
__int64 __fastcall UFG::BehaviourControllerComponent::BeginBehaviour(UFG::BehaviourControllerComponent *this, UFG::Behaviour *beh, UFG::InvokeBehaviourResult *optResult)
{
  unsigned int v3; // esi
  UFG::InvokeBehaviourResult *v4; // r14
  UFG::Behaviour *v5; // rdi
  UFG::BehaviourControllerComponent *v6; // r15
  ActionContext *v7; // rbp
  ActionContext *v8; // rbx
  ActionController *v9; // r13
  __int64 v10; // rax
  ActionNode *v11; // rcx
  ActionNodeRoot *v12; // r12
  ActionNodeRoot *v13; // rax
  ActionNodeRoot *v14; // rbp
  __int64 v15; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::SimObject *v17; // rcx
  UEL::ParametersBase *v18; // rbx
  unsigned __int16 v19; // dx
  UEL::ParametersBase *v20; // rax
  __int64 result; // rax

  v3 = 0;
  v4 = optResult;
  v5 = beh;
  v6 = this;
  if ( !beh->mParams.mInvokeTask || beh->mParams.mControlType )
    v7 = this->m_pActionContext;
  else
    v7 = beh->mParams.mInvokeTask->m_CallingActionContext;
  v8 = beh->mActionContext;
  v9 = beh->mActionController;
  v9->mKeepAlive = 0;
  v9->m_BankTracksEnabled = v7->mActionController->m_BankTracksEnabled != 0;
  v9->m_OnEnterExitCallbacksEnabled = v7->mActionController->m_OnEnterExitCallbacksEnabled != 0;
  ActionContext::operator=(v8, v7);
  v9->m_Context = v8;
  v8->mActionController = v9;
  v8->mParentContext = v7;
  v8->m_OpeningBranch = v5->mParams.mNode;
  v10 = ((__int64 (*)(void))v7->m_OpeningBranch->vfptr[1].GetResourceOwner)();
  v11 = v8->m_OpeningBranch;
  v12 = (ActionNodeRoot *)v10;
  if ( v11 )
  {
    v13 = (ActionNodeRoot *)((__int64 (*)(void))v11->vfptr[1].GetResourceOwner)();
    v14 = v13;
    if ( v13 )
    {
      v15 = v13->mActionTreeType.mValue;
      if ( (v8->mActionTreeComponentBase[v15] || v8->mActionTreeComponentBase[1]) && v12 != v13 )
      {
        v16 = v8->mActionTreeComponentBase[v15];
        if ( !v16 )
          v16 = v8->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v16, v13) )
          ActionNodeRoot::Init(v14, v8);
      }
    }
  }
  if ( v8->m_OpeningBranch )
  {
    v8->m_ActionTreeType.mValue = 2;
    v17 = v6->m_pSimObject;
    v18 = UEL::gCurrentParameters;
    if ( v17 )
    {
      v19 = v17->m_Flags;
      if ( (v19 >> 14) & 1 )
      {
        v20 = (UEL::ParametersBase *)v17->m_Components.p->m_pComponent;
      }
      else if ( (v19 & 0x8000u) == 0 )
      {
        if ( (v19 >> 13) & 1 )
          v20 = (UEL::ParametersBase *)v17->m_Components.p->m_pComponent;
        else
          v20 = (UEL::ParametersBase *)((v19 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)v17,
                                                            UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                             v17,
                                                                                             UFG::UELComponent::_TypeUID));
      }
      else
      {
        v20 = (UEL::ParametersBase *)v17->m_Components.p->m_pComponent;
      }
      if ( v20 )
        UEL::gCurrentParameters = v20 + 88;
    }
    ActionController::Play(v9);
    ActionController::updateTasksTimeBegin(v9, 0.0, 0);
    UEL::gCurrentParameters = v18;
    v3 = 1;
    v5->mAge = 0.0;
    v5->mState = 1;
  }
  result = v3;
  if ( v4 )
  {
    v4->mId = v3;
    v4->mBehaviour = v5;
  }
  return result;
}

// File Line: 956
// RVA: 0x389820
signed __int64 __fastcall UFG::BehaviourControllerComponent::SuspendBehaviour(UFG::BehaviourControllerComponent *this, UFG::Behaviour *behaviour)
{
  UFG::Behaviour *v2; // r8
  UFG::BehaviourControllerComponent *v3; // r9
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v5; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v6; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax

  v2 = behaviour;
  v3 = this;
  if ( !behaviour )
    return 0i64;
  v5 = behaviour->mPrev;
  v6 = behaviour->mNext;
  v7 = (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)&behaviour->mPrev;
  v5->mNext = v6;
  v6->mPrev = v5;
  v7->mPrev = v7;
  v7->mNext = v7;
  if ( v2 == v3->mExclusiveBehaviour )
    v3->mExclusiveBehaviour = 0i64;
  v8 = v3->mSuspendedStack.mNode.mNext;
  v3->mSuspendedStack.mNode.mNext = v7;
  v7->mPrev = &v3->mSuspendedStack.mNode;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mState = 2;
  return 3i64;
}

// File Line: 1037
// RVA: 0x394630
void __fastcall UFG::BehaviourControllerComponent::UpdateBehaviour(UFG::BehaviourControllerComponent *this, UFG::Behaviour *behaviour, float timestep)
{
  UEL::ParametersBase *v3; // rsi
  UFG::BehaviourControllerComponent *v4; // rdi
  UFG::SimObject *v5; // rcx
  UFG::Behaviour *v6; // rbx
  unsigned __int16 v7; // r8
  UEL::ParametersBase *v8; // rax
  float v9; // xmm6_4
  float v10; // xmm1_4

  v3 = UEL::gCurrentParameters;
  v4 = this;
  v5 = this->m_pSimObject;
  v6 = behaviour;
  if ( v5 )
  {
    v7 = v5->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UEL::ParametersBase *)v5->m_Components.p->m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = (UEL::ParametersBase *)v5->m_Components.p->m_pComponent;
      else
        v8 = (UEL::ParametersBase *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        (UFG::SimObjectGame *)v5,
                                                        UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         v5,
                                                                                         UFG::UELComponent::_TypeUID));
    }
    else
    {
      v8 = (UEL::ParametersBase *)v5->m_Components.p->m_pComponent;
    }
    if ( v8 )
      UEL::gCurrentParameters = v8 + 88;
  }
  ActionController::Update(v6->mActionController, timestep);
  UEL::gCurrentParameters = v3;
  v9 = timestep + v6->mAge;
  v10 = v6->mParams.mMaxLifeTime;
  v6->mAge = v9;
  if ( v10 > 0.0 && v9 > v10 || !v6->mActionController->m_currentNode )
    UFG::BehaviourControllerComponent::EndBehaviour(v4, v6);
}

// File Line: 1065
// RVA: 0x360880
__int64 __fastcall UFG::BehaviourControllerComponent::GetInvokePriorityModeFromString(const char *priorityMode)
{
  const char *v1; // rsi
  unsigned int v2; // edi
  const char **v3; // rbx

  v1 = priorityMode;
  v2 = 0;
  v3 = priorityModeNames;
  while ( (unsigned int)UFG::qStringCompareInsensitive(v1, *v3, -1) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&kfValidAngleRange )
      return 0i64;
  }
  return v2;
}

