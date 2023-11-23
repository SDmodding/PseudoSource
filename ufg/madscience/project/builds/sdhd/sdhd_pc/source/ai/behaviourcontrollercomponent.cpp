// File Line: 17
// RVA: 0x14AEAC0
__int64 dynamic_initializer_for__UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList__);
}

// File Line: 18
// RVA: 0x363350
const char *__fastcall UFG::BehaviourControllerComponent::GetTypeName(UFG::BehaviourControllerComponent *this)
{
  return "BehaviourControllerComponent";
}

// File Line: 25
// RVA: 0x37EB40
UFG::BehaviourControllerComponent *__fastcall UFG::BehaviourControllerComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::BehaviourControllerComponent *result; // rax
  const char *v8; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v14; // ebx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_AIActionTree::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
    result = (UFG::BehaviourControllerComponent *)UFG::qPropertySet::GetMemImagePtr(v5);
  else
    result = 0i64;
  if ( required || result )
  {
    v8 = (char *)result->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr
       + (unsigned __int64)result;
    if ( !result->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr )
      v8 = 0i64;
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x6C0ui64, "BehaviourControllerComponent", 0i64, 1u);
    if ( v10 )
    {
      UFG::BehaviourControllerComponent::BehaviourControllerComponent(
        (UFG::BehaviourControllerComponent *)v10,
        pSceneObj->m_NameUID,
        v8);
      v6 = v11;
    }
    m_pSimObject = pSceneObj->m_pSimObject;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v14 = 19;
    else
      v14 = -1;
    UFG::SimObjectModifier::SimObjectModifier(&v15, m_pSimObject, 1);
    UFG::SimObjectModifier::AttachComponent(&v15, v6, v14);
    UFG::SimObjectModifier::Close(&v15);
    UFG::SimObjectModifier::~SimObjectModifier(&v15);
    return (UFG::BehaviourControllerComponent *)v6;
  }
  return result;
}

// File Line: 49
// RVA: 0x32CE90
void __fastcall UFG::BehaviourControllerComponent::BehaviourControllerComponent(
        UFG::BehaviourControllerComponent *this,
        unsigned int name_uid,
        const char *actName)
{
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *mPrev; // rax

  UFG::AIActionTreeComponent::AIActionTreeComponent(this, name_uid, actName);
  this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mPrev = &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>;
  this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mNext = &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>;
  this->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::StateInterface};
  this->UFG::AIActionTreeComponent::UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::BehaviourControllerComponent::`vftable;
  this->mExclusiveBehaviour = 0i64;
  this->mParallelBehaviours.mNode.mPrev = &this->mParallelBehaviours.mNode;
  this->mParallelBehaviours.mNode.mNext = &this->mParallelBehaviours.mNode;
  this->mSuspendedStack.mNode.mPrev = &this->mSuspendedStack.mNode;
  this->mSuspendedStack.mNode.mNext = &this->mSuspendedStack.mNode;
  this->mWaitingBehaviours.mNode.mPrev = &this->mWaitingBehaviours.mNode;
  this->mWaitingBehaviours.mNode.mNext = &this->mWaitingBehaviours.mNode;
  mPrev = UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev;
  UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>;
  this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mNext = (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList;
  UFG::BehaviourControllerComponent::s_BehaviourControllerComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BehaviourControllerComponent::_BehaviourControllerComponentTypeUID,
    "BehaviourControllerComponent");
}

// File Line: 58
// RVA: 0x335740
void __fastcall UFG::BehaviourControllerComponent::~BehaviourControllerComponent(
        UFG::BehaviourControllerComponent *this)
{
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v2; // rdi
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *mPrev; // rcx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *mNext; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v5; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v6; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v9; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v10; // rax
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v11; // rcx
  UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *v12; // rax

  this->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::SimComponent};
  this->UFG::AIActionTreeComponent::UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::BehaviourControllerComponent::`vftable{for `UFG::StateInterface};
  this->UFG::AIActionTreeComponent::UFG::ActionTreeComponentBase::vfptr = (UFG::ActionTreeComponentBaseVtbl *)&UFG::BehaviourControllerComponent::`vftable;
  if ( this == UFG::BehaviourControllerComponent::s_BehaviourControllerComponentpCurrentIterator )
    UFG::BehaviourControllerComponent::s_BehaviourControllerComponentpCurrentIterator = (UFG::BehaviourControllerComponent *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mPrev[-104].mNext;
  v2 = &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>;
  mPrev = this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::BehaviourControllerComponent::ClearAllBehaviours(this);
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&this->mWaitingBehaviours);
  v5 = this->mWaitingBehaviours.mNode.mPrev;
  v6 = this->mWaitingBehaviours.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mWaitingBehaviours.mNode.mPrev = &this->mWaitingBehaviours.mNode;
  this->mWaitingBehaviours.mNode.mNext = &this->mWaitingBehaviours.mNode;
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&this->mSuspendedStack);
  v7 = this->mSuspendedStack.mNode.mPrev;
  v8 = this->mSuspendedStack.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mSuspendedStack.mNode.mPrev = &this->mSuspendedStack.mNode;
  this->mSuspendedStack.mNode.mNext = &this->mSuspendedStack.mNode;
  UFG::qList<UFG::GetInPedFormationNode,UFG::GetInPedFormationNode,1,0>::DeleteNodes((UFG::qList<UFG::HasAttackRequestNode,UFG::HasAttackRequestNode,1,0> *)&this->mParallelBehaviours);
  v9 = this->mParallelBehaviours.mNode.mPrev;
  v10 = this->mParallelBehaviours.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mParallelBehaviours.mNode.mPrev = &this->mParallelBehaviours.mNode;
  this->mParallelBehaviours.mNode.mNext = &this->mParallelBehaviours.mNode;
  v11 = v2->mPrev;
  v12 = v2->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::AIActionTreeComponent::~AIActionTreeComponent(this);
}

// File Line: 68
// RVA: 0x34ED80
void __fastcall UFG::BehaviourControllerComponent::ClearAllBehaviours(UFG::BehaviourControllerComponent *this)
{
  UFG::Behaviour *mExclusiveBehaviour; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mNext; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mPrev; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v5; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v6; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v9; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v10; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v11; // rax

  mExclusiveBehaviour = this->mExclusiveBehaviour;
  if ( mExclusiveBehaviour )
    UFG::BehaviourControllerComponent::EndBehaviour(this, mExclusiveBehaviour);
  while ( (UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> *)&this->mParallelBehaviours.mNode.mNext[-2].mNext != &this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
  {
    mNext = this->mParallelBehaviours.mNode.mNext;
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    UFG::BehaviourControllerComponent::EndBehaviour(this, (UFG::Behaviour *)&mNext[-2].mNext);
  }
  while ( (UFG::Behaviour **)&this->mSuspendedStack.mNode.mNext[-2].mNext != &this->mExclusiveBehaviour )
  {
    v6 = this->mSuspendedStack.mNode.mNext;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    v6->mNext = v6;
    UFG::BehaviourControllerComponent::EndBehaviour(this, (UFG::Behaviour *)&v6[-2].mNext);
  }
  while ( &this->mWaitingBehaviours.mNode.mNext[-2].mNext != &this->mParallelBehaviours.mNode.mNext )
  {
    v9 = this->mWaitingBehaviours.mNode.mNext;
    v10 = v9->mPrev;
    v11 = v9->mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v9->mPrev = v9;
    v9->mNext = v9;
    if ( v9 != (UFG::qNode<UFG::Behaviour,UFG::Behaviour> *)24 )
      ((void (__fastcall *)(UFG::qNode<UFG::Behaviour,UFG::Behaviour> **, __int64))v9[-2].mNext->mPrev)(
        &v9[-2].mNext,
        1i64);
  }
}

// File Line: 94
// RVA: 0x380C30
void __fastcall UFG::BehaviourControllerComponent::ReleaseActionTree(UFG::BehaviourControllerComponent *this)
{
  UFG::BehaviourControllerComponent::ClearAllBehaviours(this);
  UFG::AIActionTreeComponent::ReleaseActionTree(this);
}

// File Line: 103
// RVA: 0x378A80
// attributes: thunk
void __fastcall UFG::BehaviourControllerComponent::OnAttach(
        UFG::BehaviourControllerComponent *this,
        UFG::SimObjectCharacter *object)
{
  UFG::AIActionTreeComponent::OnAttach(this, object);
}

// File Line: 111
// RVA: 0x37A4B0
// attributes: thunk
void __fastcall UFG::BehaviourControllerComponent::OnDetach(UFG::BehaviourControllerComponent *this)
{
  UFG::AIActionTreeComponent::OnDetach(this);
}

// File Line: 119
// RVA: 0x37BDA0
void __fastcall UFG::BehaviourControllerComponent::OnUpdate(UFG::BehaviourControllerComponent *this, float delta_sec)
{
  UFG::Behaviour *mExclusiveBehaviour; // rdx
  UFG::Behaviour *p_mNext; // rdx
  UFG::BehaviourControllerComponent *v5; // rbx

  if ( (this->m_Flags & 2) == 0 )
  {
    mExclusiveBehaviour = this->mExclusiveBehaviour;
    if ( mExclusiveBehaviour && (!mExclusiveBehaviour->mParams.mInvokeTask || mExclusiveBehaviour->mParams.mControlType) )
      UFG::BehaviourControllerComponent::UpdateBehaviour(this, mExclusiveBehaviour, delta_sec);
    p_mNext = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( p_mNext != (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
    {
      do
      {
        v5 = (UFG::BehaviourControllerComponent *)&p_mNext->mNext[-2].mNext;
        if ( !p_mNext->mParams.mInvokeTask || p_mNext->mParams.mControlType )
          UFG::BehaviourControllerComponent::UpdateBehaviour(this, p_mNext, delta_sec);
        p_mNext = (UFG::Behaviour *)v5;
      }
      while ( v5 != (UFG::BehaviourControllerComponent *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> );
    }
    UFG::BehaviourControllerComponent::UpdatePendingBehaviours(this, delta_sec);
    UFG::AIActionTreeComponent::OnUpdate(this, delta_sec);
  }
}

// File Line: 154
// RVA: 0x397D70
void __fastcall UFG::BehaviourControllerComponent::UpdatePendingBehaviours(
        UFG::BehaviourControllerComponent *this,
        float timestep)
{
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **p_mNext; // rsi
  UFG::Behaviour **p_mExclusiveBehaviour; // rbp
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v6; // rdx
  UFG::Behaviour *v7; // rbx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **i; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mPrev; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mNext; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v11; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v12; // rax
  UFG::Behaviour *mExclusiveBehaviour; // rdx
  UFG::Behaviour *v14; // rdx
  float mMaxWaitTime; // xmm1_4
  float v16; // xmm0_4
  UFG::BehaviourControllerComponent *v17; // rbx

  if ( !this->mExclusiveBehaviour )
  {
    p_mNext = &this->mParallelBehaviours.mNode.mNext;
    p_mExclusiveBehaviour = &this->mExclusiveBehaviour;
    do
    {
      if ( (UFG::Behaviour **)&this->mSuspendedStack.mNode.mNext[-2].mNext == p_mExclusiveBehaviour )
        v6 = 0i64;
      else
        v6 = &this->mSuspendedStack.mNode.mNext[-2].mNext;
      v7 = 0i64;
      for ( i = &this->mWaitingBehaviours.mNode.mNext[-2].mNext; i != p_mNext; i = &i[4][-2].mNext )
      {
        if ( !v7 || v7->mParams.mPriority < *((_DWORD *)i + 14) )
          v7 = (UFG::Behaviour *)i;
      }
      if ( v6 )
      {
        if ( v7 )
        {
          if ( *((_DWORD *)v6 + 14) >= v7->mParams.mPriority )
            v7 = (UFG::Behaviour *)v6;
        }
        else
        {
          v7 = (UFG::Behaviour *)v6;
        }
      }
      else if ( !v7 )
      {
        break;
      }
      mPrev = v7->mPrev;
      mNext = v7->mNext;
      v11 = &v7->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v7->mPrev = &v7->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
      v7->mNext = &v7->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
      if ( v7->mState == eINVOKE_STATE_SUSPENDED )
      {
        if ( v7->mParams.mPriorityMode == eINVOKE_PRIORITY_PARALLEL )
        {
          v12 = this->mParallelBehaviours.mNode.mPrev;
          v12->mNext = v11;
          v11->mPrev = v12;
          v7->mNext = &this->mParallelBehaviours.mNode;
          this->mParallelBehaviours.mNode.mPrev = v11;
          this->mExclusiveBehaviour->mState = eINVOKE_STATE_RUNNING;
          this->mExclusiveBehaviour = v7;
        }
        else
        {
          mExclusiveBehaviour = this->mExclusiveBehaviour;
          if ( mExclusiveBehaviour )
            UFG::BehaviourControllerComponent::EndBehaviour(this, mExclusiveBehaviour);
          this->mExclusiveBehaviour = v7;
          v7->mState = eINVOKE_STATE_RUNNING;
          this->mExclusiveBehaviour = v7;
        }
      }
      else if ( (unsigned int)UFG::BehaviourControllerComponent::BeginBehaviour(this, v7, 0i64) == 1 )
      {
        this->mExclusiveBehaviour = v7;
      }
      else
      {
        UFG::BehaviourControllerComponent::EndBehaviour(this, v7);
      }
    }
    while ( !this->mExclusiveBehaviour );
  }
  v14 = (UFG::Behaviour *)&this->mWaitingBehaviours.mNode.mNext[-2].mNext;
  if ( v14 != (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
  {
    do
    {
      mMaxWaitTime = v14->mParams.mMaxWaitTime;
      v16 = timestep + v14->mAge;
      v17 = (UFG::BehaviourControllerComponent *)&v14->mNext[-2].mNext;
      v14->mAge = v16;
      if ( mMaxWaitTime > 0.0 && v16 > mMaxWaitTime )
        UFG::BehaviourControllerComponent::EndBehaviour(this, v14);
      v14 = (UFG::Behaviour *)v17;
    }
    while ( v17 != (UFG::BehaviourControllerComponent *)&this->mParallelBehaviours.mNode.mNext );
  }
}

// File Line: 250
// RVA: 0x369760
__int64 __fastcall UFG::BehaviourControllerComponent::InvokeBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        UFG::InvokeBehaviourResult *optResult)
{
  if ( params->mPriorityMode == eINVOKE_PRIORITY_PARALLEL )
    return UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel(this, params, optResult);
  if ( params->mIsRootInvoke )
    return UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(this, params, optResult);
  return UFG::BehaviourControllerComponent::Arbitrate_StartChild(this, params, optResult);
}

// File Line: 274
// RVA: 0x341B70
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartChild(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        UFG::InvokeBehaviourResult *optResult)
{
  unsigned int started; // esi
  UFG::Behaviour *ParentBehaviourOfTask; // r14
  UFG::eInvokeBehaviourControl mControlType; // eax
  UFG::eInvokeBehaviourPriorityMode mPriorityMode; // eax
  UFG::Behaviour *mExclusiveBehaviour; // rax
  InvokeBehaviourTask *mInvokeTask; // rax
  UFG::Behaviour *Behaviour; // rax
  UFG::Behaviour *v13; // rdi
  UFG::InvokeBehaviourParams paramsa; // [rsp+20h] [rbp-38h] BYREF

  started = 0;
  if ( optResult )
  {
    optResult->mId = 0;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  ParentBehaviourOfTask = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(this, params->mInvokeTask);
  mControlType = params->mControlType;
  if ( mControlType )
  {
    if ( mControlType != eINVOKE_AND_FORGET )
      return started;
    mPriorityMode = params->mPriorityMode;
    if ( mPriorityMode < eINVOKE_PRIORITY_KILL )
      return started;
    if ( mPriorityMode > eINVOKE_PRIORITY_KILL_OR_WAIT )
    {
      if ( mPriorityMode > eINVOKE_PRIORITY_SUSPEND_OR_WAIT )
        return started;
      mExclusiveBehaviour = this->mExclusiveBehaviour;
      if ( ParentBehaviourOfTask == mExclusiveBehaviour )
      {
        started = -1;
        if ( optResult )
        {
          optResult->mId = -1;
          optResult->mBehaviour = mExclusiveBehaviour;
          optResult->mDesc = "Child track of exclusive behaviour cannot suspend the parent.";
          optResult->mInvokeParams.mNode = params->mNode;
          *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&params->mPriority;
          *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&params->mControlType;
          *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
          optResult->mInvokeParams.mInvokeTask = params->mInvokeTask;
        }
        return started;
      }
    }
    paramsa.mNode = params->mNode;
    *(_QWORD *)&paramsa.mPriority = *(_QWORD *)&params->mPriority;
    *(_QWORD *)&paramsa.mControlType = *(_QWORD *)&params->mControlType;
    *(_QWORD *)&paramsa.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
    mInvokeTask = params->mInvokeTask;
    paramsa.mIsRootInvoke = 1;
    paramsa.mInvokeTask = mInvokeTask;
    started = UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(this, &paramsa, optResult);
    if ( started != 1 )
      return started;
  }
  Behaviour = UFG::BehaviourControllerComponent::CreateBehaviour(this, params, ParentBehaviourOfTask == 0i64, optResult);
  v13 = Behaviour;
  if ( Behaviour )
  {
    if ( ParentBehaviourOfTask )
      Behaviour->mParams.mPriority = ParentBehaviourOfTask->mParams.mPriority;
    else
      this->mExclusiveBehaviour = Behaviour;
    started = UFG::BehaviourControllerComponent::BeginBehaviour(this, Behaviour, optResult);
    if ( started != 1 )
      UFG::BehaviourControllerComponent::EndBehaviour(this, v13);
  }
  else if ( optResult )
  {
    return (unsigned int)optResult->mId;
  }
  else
  {
    return 0;
  }
  return started;
}

// File Line: 379
// RVA: 0x341F50
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartRootParallel(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        UFG::InvokeBehaviourResult *optResult)
{
  UFG::Behaviour *mExclusiveBehaviour; // rcx
  unsigned int v7; // ebp
  UFG::Behaviour *p_mNext; // rdx
  UFG::Behaviour *v9; // rdx
  const char *v10; // rax
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *p_mParallelBehaviours; // r14
  UFG::Behaviour *v12; // rcx
  UFG::Behaviour *Behaviour; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v14; // rcx
  UFG::Behaviour *v15; // rdi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mPrev; // rax

  if ( optResult )
  {
    optResult->mId = 0;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  mExclusiveBehaviour = this->mExclusiveBehaviour;
  if ( mExclusiveBehaviour && mExclusiveBehaviour->mParams.mNode == params->mNode )
  {
    v7 = -5;
    if ( optResult )
    {
      optResult->mId = -5;
      optResult->mBehaviour = mExclusiveBehaviour;
      optResult->mDesc = "Parallel behaviour requested is already running as EXCLUSIVE.";
      optResult->mInvokeParams = *params;
    }
    return v7;
  }
  p_mNext = (UFG::Behaviour *)&this->mSuspendedStack.mNode.mNext[-2].mNext;
  if ( p_mNext == (UFG::Behaviour *)&this->mExclusiveBehaviour )
  {
LABEL_11:
    v9 = (UFG::Behaviour *)&this->mWaitingBehaviours.mNode.mNext[-2].mNext;
    if ( v9 != (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
    {
      while ( v9->mParams.mNode != params->mNode )
      {
        v9 = (UFG::Behaviour *)&v9->mNext[-2].mNext;
        if ( v9 == (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
          goto LABEL_20;
      }
      UFG::BehaviourControllerComponent::EndBehaviour(this, v9);
      if ( optResult )
      {
        v10 = "Removed existing behaviour from waiting list.";
        goto LABEL_19;
      }
    }
  }
  else
  {
    while ( p_mNext->mParams.mNode != params->mNode )
    {
      p_mNext = (UFG::Behaviour *)&p_mNext->mNext[-2].mNext;
      if ( p_mNext == (UFG::Behaviour *)&this->mExclusiveBehaviour )
        goto LABEL_11;
    }
    UFG::BehaviourControllerComponent::EndBehaviour(this, p_mNext);
    if ( optResult )
    {
      v10 = "Removed existing behaviour from suspended stack.";
LABEL_19:
      optResult->mId = 0;
      optResult->mDesc = v10;
      optResult->mBehaviour = 0i64;
      optResult->mInvokeParams.mNode = params->mNode;
      *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&params->mPriority;
      *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&params->mControlType;
      *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
      optResult->mInvokeParams.mInvokeTask = params->mInvokeTask;
    }
  }
LABEL_20:
  p_mParallelBehaviours = &this->mParallelBehaviours;
  v12 = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
  if ( v12 == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
    goto LABEL_23;
  while ( v12->mParams.mNode != params->mNode )
  {
    v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
      goto LABEL_23;
  }
  if ( params->mPriority > v12->mParams.mPriority )
  {
    UFG::BehaviourControllerComponent::EndBehaviour(this, v12);
LABEL_23:
    Behaviour = UFG::BehaviourControllerComponent::CreateBehaviour(this, params, 0, 0i64);
    v14 = &Behaviour->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
    v15 = Behaviour;
    mPrev = p_mParallelBehaviours->mNode.mPrev;
    mPrev->mNext = v14;
    v14->mPrev = mPrev;
    v14->mNext = &p_mParallelBehaviours->mNode;
    p_mParallelBehaviours->mNode.mPrev = v14;
    v7 = UFG::BehaviourControllerComponent::BeginBehaviour(this, v15, optResult);
    if ( v7 != 1 )
      UFG::BehaviourControllerComponent::EndBehaviour(this, v15);
    return v7;
  }
  v7 = -5;
  if ( optResult )
  {
    optResult->mId = -5;
    optResult->mBehaviour = v12;
    optResult->mDesc = "Instance of parallel behaviour already running with higher priority.";
    optResult->mInvokeParams.mNode = params->mNode;
    *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&params->mPriority;
    *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&params->mControlType;
    *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
    optResult->mInvokeParams.mInvokeTask = params->mInvokeTask;
  }
  return v7;
}

// File Line: 446
// RVA: 0x341D30
__int64 __fastcall UFG::BehaviourControllerComponent::Arbitrate_StartRootExclusive(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        UFG::InvokeBehaviourResult *optResult)
{
  unsigned int mId; // edi
  UFG::Behaviour *mExclusiveBehaviour; // rcx
  UFG::eInvokeBehaviourPriorityMode mPriorityMode; // edx
  UFG::Behaviour *WaitingBehaviour; // rax
  UFG::Behaviour *Behaviour; // rax
  UFG::Behaviour *v11; // rsi

  mId = this->mExclusiveBehaviour == 0i64;
  if ( optResult )
  {
    optResult->mId = mId;
    optResult->mBehaviour = 0i64;
    optResult->mDesc = &customCaption;
    if ( params )
      optResult->mInvokeParams = *params;
  }
  mExclusiveBehaviour = this->mExclusiveBehaviour;
  if ( !mExclusiveBehaviour || (mPriorityMode = params->mPriorityMode, mPriorityMode < eINVOKE_PRIORITY_KILL) )
  {
LABEL_24:
    if ( mId != 1 )
      return mId;
    goto LABEL_25;
  }
  if ( mPriorityMode <= eINVOKE_PRIORITY_KILL_OR_WAIT )
  {
    if ( params->mPriority > mExclusiveBehaviour->mParams.mPriority )
    {
      UFG::BehaviourControllerComponent::EndBehaviour(this, mExclusiveBehaviour);
LABEL_25:
      Behaviour = UFG::BehaviourControllerComponent::CreateBehaviour(this, params, 1, optResult);
      v11 = Behaviour;
      if ( Behaviour )
      {
        this->mExclusiveBehaviour = Behaviour;
        mId = UFG::BehaviourControllerComponent::BeginBehaviour(this, Behaviour, optResult);
        if ( mId != 1 )
          UFG::BehaviourControllerComponent::EndBehaviour(this, v11);
      }
      else if ( optResult )
      {
        return (unsigned int)optResult->mId;
      }
      else
      {
        return 0;
      }
      return mId;
    }
    if ( mPriorityMode == eINVOKE_PRIORITY_KILL_OR_WAIT )
    {
      WaitingBehaviour = UFG::BehaviourControllerComponent::CreateWaitingBehaviour(this, params, optResult);
      if ( WaitingBehaviour )
      {
LABEL_12:
        mId = 2;
        if ( optResult )
        {
          optResult->mId = 2;
          optResult->mBehaviour = WaitingBehaviour;
          optResult->mDesc = "Waiting";
          optResult->mInvokeParams.mNode = params->mNode;
          *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&params->mPriority;
          *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&params->mControlType;
          *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
          optResult->mInvokeParams.mInvokeTask = params->mInvokeTask;
        }
        return mId;
      }
      if ( !optResult )
        return (unsigned int)-2;
      goto LABEL_23;
    }
  }
  else
  {
    if ( mPriorityMode > eINVOKE_PRIORITY_SUSPEND_OR_WAIT )
      goto LABEL_24;
    if ( params->mPriority > mExclusiveBehaviour->mParams.mPriority )
    {
      UFG::BehaviourControllerComponent::SuspendBehaviour(this, mExclusiveBehaviour);
      goto LABEL_25;
    }
    if ( mPriorityMode == eINVOKE_PRIORITY_SUSPEND_OR_WAIT )
    {
      WaitingBehaviour = UFG::BehaviourControllerComponent::CreateWaitingBehaviour(this, params, optResult);
      if ( WaitingBehaviour )
        goto LABEL_12;
      if ( !optResult )
        return (unsigned int)-2;
LABEL_23:
      mId = optResult->mId;
      goto LABEL_24;
    }
  }
  mId = -4;
  if ( optResult )
  {
    optResult->mId = -4;
    optResult->mBehaviour = mExclusiveBehaviour;
    optResult->mDesc = "Priority is lower than currently running behaviour.";
    optResult->mInvokeParams = *params;
  }
  return mId;
}

// File Line: 555
// RVA: 0x3509C0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::CreateBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        bool bCheckForDuplicates,
        UFG::InvokeBehaviourResult *optResult)
{
  bool v7; // si
  UFG::Behaviour *mExclusiveBehaviour; // rcx
  UFG::Behaviour *p_mNext; // rcx
  ActionNode *mNode; // rdx
  const char *v11; // rax
  UFG::Behaviour *v12; // rdx
  UFG::Behaviour *v13; // rdx
  UFG::allocator::free_link *v14; // rax
  _QWORD *v15; // rax
  _QWORD *v16; // rbx
  InvokeBehaviourTask *mInvokeTask; // rax
  UFG::allocator::free_link *v19; // rax
  __int64 v20; // rax
  char *v21; // rax
  __int64 v22; // rax

  v7 = !bCheckForDuplicates;
  if ( bCheckForDuplicates )
  {
    mExclusiveBehaviour = this->mExclusiveBehaviour;
    if ( mExclusiveBehaviour && mExclusiveBehaviour->mParams.mNode == params->mNode && optResult )
    {
      optResult->mId = -5;
      optResult->mDesc = "Invoked behaviour already running as exclusive, this shouldnt happen, bad logic!!";
      optResult->mBehaviour = mExclusiveBehaviour;
      optResult->mInvokeParams = *params;
    }
    p_mNext = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( p_mNext != (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
    {
      mNode = params->mNode;
      while ( p_mNext->mParams.mNode != mNode )
      {
        p_mNext = (UFG::Behaviour *)&p_mNext->mNext[-2].mNext;
        if ( p_mNext == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
          goto LABEL_16;
      }
      if ( params->mPriority <= p_mNext->mParams.mPriority )
      {
        if ( !optResult )
          goto LABEL_31;
        optResult->mId = -5;
        v11 = "Duplicate parallel behaviour with higher priority.";
        optResult->mBehaviour = p_mNext;
        goto LABEL_29;
      }
      v7 = 1;
      UFG::BehaviourControllerComponent::EndBehaviour(this, p_mNext);
      if ( !optResult )
        goto LABEL_31;
      v11 = "Behaviour removed from the Parallel list.";
LABEL_28:
      optResult->mId = 1;
      optResult->mBehaviour = 0i64;
LABEL_29:
      optResult->mDesc = v11;
      optResult->mInvokeParams.mNode = params->mNode;
      *(_QWORD *)&optResult->mInvokeParams.mPriority = *(_QWORD *)&params->mPriority;
      *(_QWORD *)&optResult->mInvokeParams.mControlType = *(_QWORD *)&params->mControlType;
      *(_QWORD *)&optResult->mInvokeParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
      optResult->mInvokeParams.mInvokeTask = params->mInvokeTask;
      goto LABEL_31;
    }
LABEL_16:
    v12 = (UFG::Behaviour *)&this->mSuspendedStack.mNode.mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&this->mExclusiveBehaviour )
    {
LABEL_22:
      v13 = (UFG::Behaviour *)&this->mWaitingBehaviours.mNode.mNext[-2].mNext;
      if ( v13 == (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
      {
LABEL_30:
        v7 = 1;
      }
      else
      {
        while ( v13->mParams.mNode != params->mNode )
        {
          v13 = (UFG::Behaviour *)&v13->mNext[-2].mNext;
          if ( v13 == (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
            goto LABEL_30;
        }
        v7 = 1;
        UFG::BehaviourControllerComponent::EndBehaviour(this, v13);
        if ( optResult )
        {
          v11 = "Behaviour removed from the Waiting list.";
          goto LABEL_28;
        }
      }
    }
    else
    {
      while ( v12->mParams.mNode != params->mNode )
      {
        v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
        if ( v12 == (UFG::Behaviour *)&this->mExclusiveBehaviour )
          goto LABEL_22;
      }
      v7 = 1;
      UFG::BehaviourControllerComponent::EndBehaviour(this, v12);
      if ( optResult )
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
    UFG::Behaviour::Behaviour((UFG::Behaviour *)v14, params);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  mInvokeTask = params->mInvokeTask;
  if ( !mInvokeTask || params->mControlType )
  {
    v19 = UFG::qMalloc(0xD8ui64, "Behaviour.ActionContext", 0i64);
    if ( v19 )
      ActionContext::ActionContext((ActionContext *)v19);
    else
      v20 = 0i64;
    v16[11] = v20;
    v21 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x118ui64, "Behaviour.ActionController", 0i64, 1u);
    if ( v21 )
      ActionController::ActionController((ActionController *)v21);
    else
      v22 = 0i64;
    v16[12] = v22;
    v16[10] = 0i64;
    return (UFG::Behaviour *)v16;
  }
  else
  {
    v16[11] = &mInvokeTask->m_ActionContext;
    v16[12] = &params->mInvokeTask->m_ActionController;
    return (UFG::Behaviour *)v16;
  }
}

// File Line: 623
// RVA: 0x357B50
UFG::qNode<UFG::Behaviour,UFG::Behaviour> **__fastcall UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(
        UFG::BehaviourControllerComponent *this,
        InvokeBehaviourTask *task,
        UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *behList)
{
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **p_mNext; // rsi
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **v5; // rbx

  p_mNext = &behList[-2].mNode.mNext;
  v5 = &behList->mNode.mNext[-2].mNext;
  if ( v5 == &behList[-2].mNode.mNext )
    return 0i64;
  while ( !task
       || !v5
       || !UFG::BehaviourControllerComponent::IsTaskChildOfController(this, task, (ActionController *)v5[12]) )
  {
    v5 = &v5[4][-2].mNext;
    if ( v5 == p_mNext )
      return 0i64;
  }
  return v5;
}

// File Line: 636
// RVA: 0x357AC0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(
        UFG::BehaviourControllerComponent *this,
        InvokeBehaviourTask *task)
{
  UFG::Behaviour *mExclusiveBehaviour; // r8
  UFG::Behaviour *result; // rax

  mExclusiveBehaviour = this->mExclusiveBehaviour;
  if ( !mExclusiveBehaviour
    || !task
    || !UFG::BehaviourControllerComponent::IsTaskChildOfController(this, task, mExclusiveBehaviour->mActionController)
    || (result = this->mExclusiveBehaviour) == 0i64 )
  {
    result = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(this, task, &this->mParallelBehaviours);
    if ( !result )
    {
      result = UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(this, task, &this->mSuspendedStack);
      if ( !result )
        return UFG::BehaviourControllerComponent::FindParentBehaviourOfTask(this, task, &this->mWaitingBehaviours);
    }
  }
  return result;
}

// File Line: 665
// RVA: 0x355F00
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindBehaviourWithNode(
        UFG::BehaviourControllerComponent *this,
        const char *nodePath)
{
  UFG::Behaviour *BehaviourWithNode; // rbx
  ActionNode *v4; // rax
  int mCount; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  BehaviourWithNode = 0i64;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, nodePath);
  v4 = ActionNode::Find(&absolutePath, 0i64);
  if ( v4 )
    BehaviourWithNode = UFG::BehaviourControllerComponent::FindBehaviourWithNode(this, v4);
  mCount = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
    {
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
      mCount = absolutePath.mPath.mCount;
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = mCount & 0x80000000;
  }
  return BehaviourWithNode;
}

// File Line: 677
// RVA: 0x355FA0
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::FindBehaviourWithNode(
        UFG::BehaviourControllerComponent *this,
        ActionNode *node)
{
  UFG::Behaviour *result; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mNext; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> **p_mNext; // rcx

  result = this->mExclusiveBehaviour;
  if ( !result || result->mParams.mNode != node )
  {
    result = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
    if ( result == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
    {
LABEL_6:
      result = (UFG::Behaviour *)&this->mSuspendedStack.mNode.mNext[-2].mNext;
      if ( result == (UFG::Behaviour *)&this->mExclusiveBehaviour )
      {
LABEL_9:
        mNext = this->mWaitingBehaviours.mNode.mNext;
        p_mNext = &this->mParallelBehaviours.mNode.mNext;
        result = (UFG::Behaviour *)&mNext[-2].mNext;
        if ( result == (UFG::Behaviour *)p_mNext )
        {
          return 0i64;
        }
        else
        {
          while ( result->mParams.mNode != node )
          {
            result = (UFG::Behaviour *)&result->mNext[-2].mNext;
            if ( result == (UFG::Behaviour *)p_mNext )
              return 0i64;
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
        if ( result == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
          goto LABEL_6;
      }
    }
  }
  return result;
}

// File Line: 709
// RVA: 0x351620
UFG::Behaviour *__fastcall UFG::BehaviourControllerComponent::CreateWaitingBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::InvokeBehaviourParams *params,
        UFG::InvokeBehaviourResult *optResult)
{
  UFG::Behaviour *mExclusiveBehaviour; // rcx
  UFG::Behaviour *Behaviour; // r9
  UFG::qList<UFG::Behaviour,UFG::Behaviour,1,0> *p_mWaitingBehaviours; // rsi
  UFG::Behaviour *p_mNext; // rcx
  ActionNode *mNode; // rdx
  UFG::Behaviour *v11; // rax
  UFG::Behaviour *v12; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mPrev; // rcx

  mExclusiveBehaviour = this->mExclusiveBehaviour;
  Behaviour = 0i64;
  if ( mExclusiveBehaviour && mExclusiveBehaviour->mParams.mNode == params->mNode )
  {
    if ( optResult )
    {
      optResult->mId = -5;
      optResult->mBehaviour = mExclusiveBehaviour;
      optResult->mDesc = "Invoked behaviour already running as exclusive.";
      optResult->mInvokeParams = *params;
      return 0i64;
    }
    return Behaviour;
  }
  p_mWaitingBehaviours = &this->mWaitingBehaviours;
  p_mNext = (UFG::Behaviour *)&this->mWaitingBehaviours.mNode.mNext[-2].mNext;
  if ( p_mNext != (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
  {
    mNode = params->mNode;
    while ( p_mNext->mParams.mNode != mNode )
    {
      p_mNext = (UFG::Behaviour *)&p_mNext->mNext[-2].mNext;
      if ( p_mNext == (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext )
        goto LABEL_9;
    }
    Behaviour = p_mNext;
    if ( params->mPriority > p_mNext->mParams.mPriority )
    {
      p_mNext->mParams.mNode = mNode;
      *(_QWORD *)&p_mNext->mParams.mPriority = *(_QWORD *)&params->mPriority;
      *(_QWORD *)&p_mNext->mParams.mControlType = *(_QWORD *)&params->mControlType;
      *(_QWORD *)&p_mNext->mParams.mMaxLifeTime = *(_QWORD *)&params->mMaxLifeTime;
      p_mNext->mParams.mInvokeTask = params->mInvokeTask;
      return p_mNext;
    }
    return Behaviour;
  }
LABEL_9:
  v11 = (UFG::Behaviour *)&this->mParallelBehaviours.mNode.mNext[-2].mNext;
  if ( v11 != (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
  {
    while ( v11->mParams.mNode != params->mNode )
    {
      v11 = (UFG::Behaviour *)&v11->mNext[-2].mNext;
      if ( v11 == (UFG::Behaviour *)&this->UFG::qNode<UFG::BehaviourControllerComponent,UFG::BehaviourControllerComponent> )
        goto LABEL_12;
    }
    if ( !optResult )
      return Behaviour;
    optResult->mBehaviour = v11;
    optResult->mDesc = "Behaviour already running as parallel.";
    goto LABEL_25;
  }
LABEL_12:
  v12 = (UFG::Behaviour *)&this->mSuspendedStack.mNode.mNext[-2].mNext;
  if ( v12 == (UFG::Behaviour *)&this->mExclusiveBehaviour )
  {
LABEL_15:
    Behaviour = UFG::BehaviourControllerComponent::CreateBehaviour(this, params, 0, 0i64);
    Behaviour->mState = eINVOKE_STATE_WAITING;
    mPrev = p_mWaitingBehaviours->mNode.mPrev;
    mPrev->mNext = &Behaviour->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
    Behaviour->mPrev = mPrev;
    Behaviour->mNext = &p_mWaitingBehaviours->mNode;
    p_mWaitingBehaviours->mNode.mPrev = &Behaviour->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
    return Behaviour;
  }
  while ( v12->mParams.mNode != params->mNode )
  {
    v12 = (UFG::Behaviour *)&v12->mNext[-2].mNext;
    if ( v12 == (UFG::Behaviour *)&this->mExclusiveBehaviour )
      goto LABEL_15;
  }
  if ( params->mPriority > v12->mParams.mPriority )
  {
    UFG::BehaviourControllerComponent::EndBehaviour(this, v12);
    goto LABEL_15;
  }
  if ( !optResult )
    return Behaviour;
  optResult->mBehaviour = v12;
  optResult->mDesc = "Behaviour with higher priority is in the Suspended stack.";
LABEL_25:
  optResult->mId = -5;
  optResult->mInvokeParams = *params;
  return 0i64;
}

// File Line: 764
// RVA: 0x355780
__int64 __fastcall UFG::BehaviourControllerComponent::EndBehaviour(
        UFG::BehaviourControllerComponent *this,
        const char *nodePath)
{
  ActionNode *v3; // rax
  unsigned int v4; // ebx
  UFG::Behaviour *BehaviourWithNode; // rax
  int mCount; // edx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  if ( !nodePath || !*nodePath )
    return UFG::BehaviourControllerComponent::EndBehaviour(this, this->mExclusiveBehaviour);
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, nodePath);
  v3 = ActionNode::Find(&absolutePath, 0i64);
  if ( v3 )
  {
    BehaviourWithNode = UFG::BehaviourControllerComponent::FindBehaviourWithNode(this, v3);
    v4 = UFG::BehaviourControllerComponent::EndBehaviour(this, BehaviourWithNode);
  }
  else
  {
    v4 = -3;
  }
  mCount = absolutePath.mPath.mCount;
  if ( absolutePath.mPath.mCount >= 0 )
  {
    if ( absolutePath.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      {
        operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
        mCount = absolutePath.mPath.mCount;
      }
    }
    absolutePath.mPath.mData.mOffset = 0i64;
    absolutePath.mPath.mCount = mCount & 0x80000000;
  }
  return v4;
}

// File Line: 784
// RVA: 0x355690
__int64 __fastcall UFG::BehaviourControllerComponent::EndBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::Behaviour *behaviour)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v5; // rsi
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax

  if ( behaviour )
  {
    if ( behaviour->mActionController )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
      v5 = UEL::gCurrentParameters;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
          else
            m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pSimObject,
                                                     UFG::UELComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     m_pSimObject,
                                                     UFG::UELComponent::_TypeUID));
        }
        else
        {
          m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
        }
        if ( m_pComponent )
          UEL::gCurrentParameters = m_pComponent + 88;
      }
      ActionController::Stop(behaviour->mActionController);
      UEL::gCurrentParameters = v5;
    }
    if ( behaviour == this->mExclusiveBehaviour )
      this->mExclusiveBehaviour = 0i64;
    behaviour->vfptr->__vecDelDtor(behaviour, 1i64);
  }
  return 1i64;
}

// File Line: 828
// RVA: 0x36BC80
bool __fastcall UFG::BehaviourControllerComponent::IsTaskChildOfController(
        UFG::BehaviourControllerComponent *this,
        ITask *task,
        ActionController *controller)
{
  ITask *p_mNext; // rbx
  bool IsTaskChildOfController; // di
  ITrack *m_Track; // rsi

  if ( !task )
    return 0;
  p_mNext = (ITask *)&controller->m_RunningTasks.mNode.mNext[-1].mNext;
  if ( p_mNext == (ITask *)&controller->m_SequenceNode )
    return 0;
  do
  {
    IsTaskChildOfController = p_mNext == task;
    if ( p_mNext == task )
      break;
    m_Track = p_mNext->m_Track;
    if ( SpawnTrack::sClassNameUID == m_Track->vfptr->GetClassNameUID(m_Track)
      || InvokeBehaviourTrack::sClassNameUID == m_Track->vfptr->GetClassNameUID(m_Track) )
    {
      IsTaskChildOfController = UFG::BehaviourControllerComponent::IsTaskChildOfController(
                                  this,
                                  task,
                                  (ActionController *)&p_mNext[7].UFG::qNode<ITask,ITask>);
      if ( IsTaskChildOfController )
        break;
    }
    p_mNext = (ITask *)&p_mNext->mNext[-1].mNext;
  }
  while ( p_mNext != (ITask *)&controller->m_SequenceNode );
  return IsTaskChildOfController;
}

// File Line: 864
// RVA: 0x3491E0
__int64 __fastcall UFG::BehaviourControllerComponent::BeginBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::Behaviour *beh,
        UFG::InvokeBehaviourResult *optResult)
{
  unsigned int v3; // esi
  ActionContext *m_pActionContext; // rbp
  ActionContext *mActionContext; // rbx
  ActionController *mActionController; // r13
  __int64 v10; // rax
  ActionNode *m_OpeningBranch; // rcx
  ActionNodeRoot *v12; // r12
  ActionNodeRoot *v13; // rax
  ActionNodeRoot *v14; // rbp
  __int64 mValue; // rdx
  UFG::ActionTreeComponentBase *v16; // rcx
  UFG::SimObjectGame *m_pSimObject; // rcx
  UEL::ParametersBase *v18; // rbx
  __int16 m_Flags; // dx
  UEL::ParametersBase *m_pComponent; // rax
  __int64 result; // rax

  v3 = 0;
  if ( !beh->mParams.mInvokeTask || beh->mParams.mControlType )
    m_pActionContext = this->m_pActionContext;
  else
    m_pActionContext = beh->mParams.mInvokeTask->m_CallingActionContext;
  mActionContext = beh->mActionContext;
  mActionController = beh->mActionController;
  mActionController->mKeepAlive = 0;
  mActionController->m_BankTracksEnabled = m_pActionContext->mActionController->m_BankTracksEnabled != 0;
  mActionController->m_OnEnterExitCallbacksEnabled = m_pActionContext->mActionController->m_OnEnterExitCallbacksEnabled != 0;
  ActionContext::operator=(mActionContext, m_pActionContext);
  mActionController->m_Context = mActionContext;
  mActionContext->mActionController = mActionController;
  mActionContext->mParentContext = m_pActionContext;
  mActionContext->m_OpeningBranch = beh->mParams.mNode;
  v10 = (__int64)m_pActionContext->m_OpeningBranch->vfptr[1].GetResourceOwner(m_pActionContext->m_OpeningBranch);
  m_OpeningBranch = mActionContext->m_OpeningBranch;
  v12 = (ActionNodeRoot *)v10;
  if ( m_OpeningBranch )
  {
    v13 = (ActionNodeRoot *)m_OpeningBranch->vfptr[1].GetResourceOwner(m_OpeningBranch);
    v14 = v13;
    if ( v13 )
    {
      mValue = v13->mActionTreeType.mValue;
      if ( (mActionContext->mActionTreeComponentBase[mValue] || mActionContext->mActionTreeComponentBase[1])
        && v12 != v13 )
      {
        v16 = mActionContext->mActionTreeComponentBase[mValue];
        if ( !v16 )
          v16 = mActionContext->mActionTreeComponentBase[1];
        if ( UFG::ActionTreeComponentBase::AllocateFor(v16, v13) )
          ActionNodeRoot::Init(v14, mActionContext);
      }
    }
  }
  if ( mActionContext->m_OpeningBranch )
  {
    mActionContext->m_ActionTreeType.mValue = 2;
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    v18 = UEL::gCurrentParameters;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
        else
          m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   m_pSimObject,
                                                   UFG::UELComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   m_pSimObject,
                                                   UFG::UELComponent::_TypeUID));
      }
      else
      {
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      }
      if ( m_pComponent )
        UEL::gCurrentParameters = m_pComponent + 88;
    }
    ActionController::Play(mActionController);
    ActionController::updateTasksTimeBegin(mActionController, 0.0, 0);
    UEL::gCurrentParameters = v18;
    v3 = 1;
    beh->mAge = 0.0;
    beh->mState = eINVOKE_STATE_RUNNING;
  }
  result = v3;
  if ( optResult )
  {
    optResult->mId = v3;
    optResult->mBehaviour = beh;
  }
  return result;
}( optResult )


// File Line: 956
// RVA: 0x389820
__int64 __fastcall UFG::BehaviourControllerComponent::SuspendBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::Behaviour *behaviour)
{
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mPrev; // rcx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *mNext; // rax
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v7; // rdx
  UFG::qNode<UFG::Behaviour,UFG::Behaviour> *v8; // rax

  if ( !behaviour )
    return 0i64;
  mPrev = behaviour->mPrev;
  mNext = behaviour->mNext;
  v7 = &behaviour->UFG::qNode<UFG::Behaviour,UFG::Behaviour>;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  if ( behaviour == this->mExclusiveBehaviour )
    this->mExclusiveBehaviour = 0i64;
  v8 = this->mSuspendedStack.mNode.mNext;
  this->mSuspendedStack.mNode.mNext = v7;
  v7->mPrev = &this->mSuspendedStack.mNode;
  v7->mNext = v8;
  v8->mPrev = v7;
  behaviour->mState = eINVOKE_STATE_SUSPENDED;
  return 3i64;
}

// File Line: 1037
// RVA: 0x394630
void __fastcall UFG::BehaviourControllerComponent::UpdateBehaviour(
        UFG::BehaviourControllerComponent *this,
        UFG::Behaviour *behaviour,
        float timestep)
{
  UEL::ParametersBase *v3; // rsi
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // r8
  UEL::ParametersBase *m_pComponent; // rax
  float v9; // xmm6_4
  float mMaxLifeTime; // xmm1_4

  v3 = UEL::gCurrentParameters;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
        m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
      else
        m_pComponent = (UEL::ParametersBase *)((m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pSimObject,
                                                 UFG::UELComponent::_TypeUID));
    }
    else
    {
      m_pComponent = (UEL::ParametersBase *)m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
      UEL::gCurrentParameters = m_pComponent + 88;
  }
  ActionController::Update(behaviour->mActionController, timestep);
  UEL::gCurrentParameters = v3;
  v9 = timestep + behaviour->mAge;
  mMaxLifeTime = behaviour->mParams.mMaxLifeTime;
  behaviour->mAge = v9;
  if ( mMaxLifeTime > 0.0 && v9 > mMaxLifeTime || !behaviour->mActionController->m_currentNode )
    UFG::BehaviourControllerComponent::EndBehaviour(this, behaviour);
}

// File Line: 1065
// RVA: 0x360880
__int64 __fastcall UFG::BehaviourControllerComponent::GetInvokePriorityModeFromString(const char *priorityMode)
{
  unsigned int v2; // edi
  const char **v3; // rbx

  v2 = 0;
  v3 = priorityModeNames;
  while ( (unsigned int)UFG::qStringCompareInsensitive(priorityMode, *v3, -1) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)&kfValidAngleRange )
      return 0i64;
  }
  return v2;
}

